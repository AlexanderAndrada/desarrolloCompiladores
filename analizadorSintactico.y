
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
int buscarPut;
int tipoVariable;


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
%right SUMA MULTIPLICACION
%token COMENTARIO CONCAT
%token RESTA DIVISION ASIG
%token MAYOR MENOR MAYORIGUAL MENORIGUAL IGUAL DISTINTO
%token PUNTOYCOMA ABRIRPARENTESIS CERRARPARENTESIS ABRIRLLAVE CERRARLLAVE ABRIRCORCHETE CERRARCORCHETE
%token IF ELSE WHILE PUT GET AND OR DECLARE
%token <var> INT 
%token <var> FLOAT 
%token DOUBLE BOOLEAN
%token ASIGESPMAS ASIGESPMENOS ASIGESPMULTIPLICACION ASIGESPDIVISION
%token <var> STRING
%token JNA
%token ENDIF TRUE ENDSENTENCE ENDWHILE

%type <var> identificadorintermedio


%%
programa:
	MAIN ABRIRLLAVE declaracion sentencias CERRARLLAVE {
		printf("Main OK\n");
		escribirTablaSimbolos();
		guardarArchivoTercetos();
		generarAssembler(devolverTercetos(),devolverCantidadTercetos(),devolverTercetoResultado(),devolverCantidadSimbolos());
		}
	|MAIN ABRIRLLAVE sentencias CERRARLLAVE {
		printf("Main OK\n");
		escribirTablaSimbolos();
		guardarArchivoTercetos();

		generarAssembler(devolverTercetos(),devolverCantidadTercetos(),devolverTercetoResultado(),devolverCantidadSimbolos());
		}
	;

declaracion:
	DECLARE sentenciadeclaracion PUNTOYCOMA {printf("Declaraciones ok\n");}
	;

sentenciadeclaracion:
	tipo identificadorintermedio 
	|sentenciadeclaracion tipo identificadorintermedio 
	;

tipo: 
	FLOAT {
		tipoVariable=FLOAT;}
	|INT {
		tipoVariable=INT;}
	|STRING {
		tipoVariable=STRING;}
	|BOOLEAN {
		tipoVariable=BOOLEAN;}
	|DOUBLE {
		tipoVariable=DOUBLE;}
	;

identificadorintermedio:
	IDENTIFICADOR {
		indiceIdentificador = buscarPosicionTablaSimbolos($1);
		validarExistenciaVariable(indiceIdentificadorIntermedio,$1);
		indiceTipo = agregarTipoTablaDeSimbolos(tipoVariable);
		indiceIdentificadorIntermedio = agregarNombreTablaDeSimbolos(indiceTipo,$1);
		crear_terceto(NOOP, NOOP, indiceIdentificadorIntermedio);
		contadorVariables++;
		}
	|identificadorintermedio IDENTIFICADOR{
		indiceIdentificador = buscarPosicionTablaSimbolos($2);
		validarExistenciaVariable(indiceIdentificadorIntermedio,$2);
		indiceTipo = agregarTipoTablaDeSimbolos(tipoVariable);		
		indiceIdentificadorIntermedio = agregarNombreTablaDeSimbolos(indiceTipo,$2);
		crear_terceto(NOOP, NOOP, indiceIdentificadorIntermedio);
		contadorVariables++;		
		}
	;
	
sentencias:
	sentencia PUNTOYCOMA {printf("Sentencia ok\n");}
	|sentencias sentencia
	;

sentencia:
	WHILE sentenciawhile {printf("While ok\n");}
	|IF sentenciaif {printf("If ok\n");}
	|expresion {printf("Expresion ok\n");}
	|asignacion {printf("Asignacion ok\n");}
	|asignacionespecial {printf("Asignacion especial ok\n");}
	|lectura
	|escritura
	;
/*
sentenciaparentesis:
	ABRIRPARENTESIS IDENTIFICADOR CERRARPARENTESIS{
		indiceIdentificador = buscarPosicionTablaSimbolos($2);
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		crear_terceto(PUT, NOOP, indiceAsignacion);}
	|ABRIRPARENTESIS STRING CERRARPARENTESIS{
		indiceString = agregarTipoTablaDeSimbolos(STRING);
		indiceString = agregarNombreTablaDeSimbolos(indiceString,$2);
		indiceString = crear_terceto(NOOP, NOOP, indiceString);
		indiceString = crear_terceto(PUT, NOOP, indiceString);
	}
	;

factorparentesis:
	ABRIRPARENTESIS IDENTIFICADOR CERRARPARENTESIS{
		indiceIdentificador = buscarPosicionTablaSimbolos($2);
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		crear_terceto(GET, NOOP, indiceAsignacion);
		}
	;
*/
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
		compararTipoVariable($1,buscarExpresion);
		indiceIdentificador = buscarPosicionTablaSimbolos($1);
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		crear_terceto(ASIG, indiceExpresion, indiceAsignacion);
		printf("Var: %s Asignacion ok\n",$1);
		}
	|IDENTIFICADOR ASIG expresionstrings {
		compararTipoVariable($1,buscarString);
		agregarVariableATablaDeSimbolos($1, IDENTIFICADOR);
		indiceIdentificador = buscarPosicionTablaSimbolos($1);
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		crear_terceto(ASIG, indiceString, indiceAsignacion);
		printf("Var: %s Asignacion ok\n",$1);
		}
	;

asignacionespecial:
	IDENTIFICADOR asignadorespecial {
		indiceIdentificador = buscarPosicionTablaSimbolos($1);
		indiceAsignacion = buscar_terceto(indiceIdentificador,contadorVariables);
		indiceAsignacionEspecial = crear_terceto(indiceAsignacionEspecial, indiceExpresion, indiceAsignacion);
		indiceAsignacionEspecial = crear_terceto(ASIG,indiceAsignacionEspecial,indiceAsignacion);
		printf("asigesp es: %d\n", indiceAsignacionEspecial );
		}
	;

asignadorespecial:
	ASIGESPMAS expresion {indiceAsignacionEspecial=SUMA;}
	|ASIGESPMENOS expresion {indiceAsignacionEspecial=RESTA;}
	|ASIGESPMULTIPLICACION expresion {indiceAsignacionEspecial=MULTIPLICACION;}
	|ASIGESPDIVISION expresion {indiceAsignacionEspecial=DIVISION;}
	;

expresionstrings:
	expresionconcat
	|STRING {
		indiceString = agregarTipoTablaDeSimbolos(STRING);
		indiceString = agregarNombreTablaDeSimbolos(indiceString,$1);
		indiceString = crear_terceto(NOOP, NOOP, indiceString);
		buscarString = $1;
		printf("El string es: %s ",$1);
		}
	;
	
expresionconcat:
	STRING CONCAT STRING {
		verificarLargoString($1,$3);
		indiceString = agregarTipoTablaDeSimbolos(STRING);
		indiceString = agregarNombreTablaDeSimbolos(indiceString,$1);
		indiceStringAux = agregarTipoTablaDeSimbolos(STRING);
		indiceStringAux = agregarNombreTablaDeSimbolos(indiceStringAux,$3);
		indiceString = crear_terceto(NOOP, NOOP, indiceString);
		indiceStringAux = crear_terceto(NOOP, NOOP, indiceStringAux);
		indiceString = crear_terceto(CONCAT, indiceStringAux, indiceString);
		buscarString = $1;		
		printf("El string es: %s %s ",$1,$3);
		}
	;


expresion2:
	expresion {indiceExpresion2 = indiceExpresion;}
	;

expresion:
	termino {
		indiceExpresion = indiceTermino;
		buscarExpresion=buscarTermino;}
	|expresion RESTA termino {
		compararTipoVariable(buscarTermino,buscarExpresion);	
		printf("Resta OK\n");
		indiceExpresion=crear_terceto(RESTA, indiceExpresion,indiceTermino);
		}
	|expresion SUMA termino  {
		compararTipoVariable(buscarTermino,buscarExpresion);	
		printf("Suma OK\n");
		indiceExpresion=crear_terceto(SUMA, indiceExpresion,indiceTermino);
		}
	;

termino:
	factor {
		indiceTermino = indiceFactor;
		buscarTermino=buscarFactor;}
	|termino MULTIPLICACION factor  {
		compararTipoVariable(buscarFactor,buscarTermino);
		printf("Multiplicacion OK\n");
		indiceTermino=crear_terceto(MULTIPLICACION, indiceFactor,indiceTermino);
		   }
	|termino DIVISION factor {
		compararTipoVariable(buscarFactor,buscarTermino);		
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
		indiceIdentificador = buscarPosicionTablaSimbolos($1);
		validarExistenciaVariable(indiceIdentificador,$1);
		indiceFactor = buscar_terceto(indiceIdentificador,contadorVariables);
		buscarFactor=$1;			
		}
	|INT {
		indiceConstante = agregarTipoTablaDeSimbolos(INT);
		indiceConstante = agregarNombreTablaDeSimbolos(indiceConstante,$1);
		indiceFactor = crear_terceto(NOOP, NOOP, indiceConstante);
		buscarFactor=$1;		
		}
	|FLOAT {
		indiceReal = agregarTipoTablaDeSimbolos(FLOAT);
		indiceReal = agregarNombreTablaDeSimbolos(indiceReal,$1);
		indiceFactor = crear_terceto(NOOP, NOOP, indiceReal);
		buscarFactor=$1;		
		}
	;

	lectura:
		GET IDENTIFICADOR	{
	//	crear_terceto(GET, NOOP, indiceIdentificador);

		}
	;

	escritura:
		PUT IDENTIFICADOR {
		crear_terceto(PUT, NOOP, indiceIdentificador);
		}
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