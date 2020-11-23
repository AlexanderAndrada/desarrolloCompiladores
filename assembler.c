#include <stdio.h>
#include <stdlib.h>
#include "assembler.h"
#include "y.tab.h"
#include "tercetos.h"

int ultimo_terceto;
int fin_tabla;
FILE *fileSimbolos;

struct tercetoResultado{
	char operador[20];
	char op1[20];
	char op2[20];
};

struct terceto{
	int operador;
	int op1;
	int op2;
};

  struct tabla_simbolo
  {
      char nombre[20];
      char tipo[20];
	  int tipoToken;
      char valor[20];
      int longitud;
  } tabla_simbolo[100]={0};

struct terceto *lista_terceto;
struct tercetoResultado *listaTercetosResultado;
//struct tabla_simbolo *tabla_simbolo;


    void lecturaArchivoDeSimbolos(){
        char lineaSimbolo[80]={0};
        char indiceLineaSimbolo=0;
        char caracter;
        int contadorNombre=0;
        char nombre[20]={0};
        char tipo[20]={0};
        char valor[20]={0};
        char cadenaSeparada[20]={0};
        int i;
        int borrar;
        int x,y,z,c;
        int indiceCopiar=0 ;
		int contadorDeSimbolos=0;
		int tokenTipoAux;


		fileSimbolos = fopen("tablaSimboloss.txt","r");

		if (fileSimbolos == NULL)
        {
            printf("\nError de apertura del archivo. \n\n");
        }else{

        while((caracter = fgetc(fileSimbolos)) != EOF){
			
            if(caracter!='\n'){
                lineaSimbolo[indiceLineaSimbolo]=caracter;
			
                indiceLineaSimbolo++;
            }
            else{
               // contadorDeSimbolos++;

                for(x=0; x < 20; x++){
                    if(strlen(nombre)<19){
                        nombre[x]=lineaSimbolo[x];
                    }
                }

                indiceCopiar=0;


                 for(y=20; y < 40; y++){
                        if(strlen(tipo)<19){
                            tipo[indiceCopiar]=lineaSimbolo[y];
                            indiceCopiar++;
                        }
                }

				tokenTipoAux = devolverNumeroTipo(tipo);
				if(tokenTipoAux != -1){
					tabla_simbolo[contadorDeSimbolos].tipoToken = tokenTipoAux;
				}
                indiceCopiar=0;

                 for(z=40; z < 60; z++){
                     if(strlen(valor)<19){
                         valor[indiceCopiar]=lineaSimbolo[z];
                         indiceCopiar++;
                     }
                }

                indiceCopiar=0;

                 for(c=60; c < 80; c++){
                    cadenaSeparada[indiceCopiar] = lineaSimbolo[c];
                    indiceCopiar++;
                }

                if(c == 80){

                    if(strcmp(cadenaSeparada,"                   ")==0){

						tabla_simbolo[contadorDeSimbolos].longitud = 0;
                    }else{
                        tabla_simbolo[contadorDeSimbolos].longitud = atoi(cadenaSeparada);
                    }
                    indiceCopiar = 0;
                }


				char nombreCopiar[20]={0};

                strncpy(tabla_simbolo[contadorDeSimbolos].nombre, nombre, 19);
                strncpy(tabla_simbolo[contadorDeSimbolos].tipo, tipo, 19);
                strncpy(tabla_simbolo[contadorDeSimbolos].valor, valor, 19);

                contadorDeSimbolos++;
                indiceLineaSimbolo=0;

            for(borrar=0; borrar < 80; borrar++){
                lineaSimbolo[borrar]='\0';
            }
            for(borrar=0; borrar < 20; borrar++){
                nombre[borrar]='\0';
                tipo[borrar]='\0';
                valor[borrar]='\0';
                cadenaSeparada[borrar]='\0';

            }
            }

        }
	close(fileSimbolos);
	}
    }







void generarAssembler(struct terceto *listaTerceto,int ultimoTerceto, struct tercetoResultado *tercetoResult, int finTabla)
{
	lista_terceto = listaTerceto;
	listaTercetosResultado = tercetoResult;

	printf("Op 1 es: %s\n", listaTercetosResultado[3].op1);
	printf("Op 2 es: %s\n", listaTercetosResultado[3].op2);

	printf("Op1 en posicion 0 es: %s\n", listaTercetosResultado[0].op2);
	printf("Op2 en posicion 0 es: %s\n", listaTercetosResultado[1].op2);
	
	lecturaArchivoDeSimbolos();

	ultimo_terceto = ultimoTerceto;
	fin_tabla = finTabla;

  FILE* arch = fopen("Final.asm", "w");
  if(!arch){
		printf("No pude crear el archivo final.txt\n");
		return;
	}

  escribirInicio(arch);
  generarTabla(arch);
  escribirInicioCodigo(arch);

  for(int i=0; i <= ultimo_terceto; i++){
    switch(lista_terceto[i].operador){
      case ASIG:
	  	asignacion(arch, i);
        break;
      case CMP:
		comparacion(arch, i);
        break;

      case BGT:
        escribirSalto(arch, "JA", lista_terceto[i].op2);
        break;
      case BGE:
        escribirSalto(arch, "JAE", lista_terceto[i].op2);
        break;
      case BLT:
        escribirSalto(arch, "JB", lista_terceto[i].op2);
        break;
      case BLE:
        escribirSalto(arch, "JBE", lista_terceto[i].op2);
        break;
      case BNE:
        escribirSalto(arch, "JNE", lista_terceto[i].op2);
        break;
      case BEQ:
        escribirSalto(arch, "JE", lista_terceto[i].op2);
        break;
      case JMP:
        escribirSalto(arch, "JMP", lista_terceto[i].op1);
        break;

   //   case THEN:
     //   escribirEtiqueta(arch, "then", i);
       // break;
      case ELSE:
        escribirEtiqueta(arch, "else", i);
        break;
      case ENDIF:
        escribirEtiqueta(arch, "endif", i);
        break;

      case WHILE:
        escribirEtiqueta(arch, "while", i);
        break;
      case ENDWHILE:
        escribirEtiqueta(arch, "endwhile", i);
        break;

	//case INLIST_TRUE:
	//	escribirEtiqueta(arch, "inlistTrue", i);
	//	break;
	//case INLIST_CMP:
	//	escribirEtiqueta(arch, "inlistCMP", i);
	//	break;

      case SUMA:
		suma(arch,i);
        break;
     // case RESTA:
		//resta(arch,i);
        //break;
      case MULTIPLICACION:
		multiplicacion(arch,i);
        break;
      case DIVISION:
		division(arch,i);
        break;

      //case READ: read (arch,i);
      //  break;
      //case WRITE:
	  	//write(arch, i);
      //  break;
    }
  }

  escribirFinal(arch);
  fclose(arch);

}

void escribirInicio(FILE *arch){
  fprintf(arch, "include macros2.asm\ninclude number.asm\n\n.MODEL SMALL\n.386\n.STACK 200h\n\n");
}

void escribirInicioCodigo(FILE* arch){
	fprintf(arch, ".CODE\nMAIN:\n\nMOV AX, @DATA\nMOV DS, AX\n\n");
}

void escribirFinal(FILE *arch){
    fprintf(arch, "\nMOV AH, 1\nINT 21h\nMOV AX, 4C00h\nINT 21h\n\nEND MAIN\n");
	// TODO: Preguntar por flags y escribir subrutinas
}

void generarTabla(FILE *arch){
    fprintf(arch, ".DATA\n");
    //fprintf(arch, "NEW_LINE DB 0AH,0DH,'$'\n");
	//fprintf(arch, "CWprevio DW ?\n");

    for(int i=0; i<=fin_tabla; i++){
        fprintf(arch, "%s ", tabla_simbolo[i].nombre);
		
        switch(tabla_simbolo[i].tipoToken){
        case INT:
            //fprintf(arch, "db %d\n", tabla_simbolo[i].valor);
			fprintf(arch, "db %d\n", 2);
            break;
        case FLOAT:
            fprintf(arch, "dd %f\n", tabla_simbolo[i].valor);
            break;
        case STRING:
            fprintf(arch, "db \"%s\", '$'\n", tabla_simbolo[i].valor);
            break;
        default: //Es una variable int, float o puntero a string
            //fprintf(arch, "dd ?\n");
			printf("");
        }
    }

    fprintf(arch, "\n");
}

void escribirEtiqueta(FILE* arch, char* etiqueta, int n){
    fprintf(arch, "%s%d:\n", etiqueta, n);
}

void escribirSalto(FILE* arch, char* salto, int tercetoDestino){
    fprintf(arch, "%s ", salto);

    //Por si nos olvidamos de rellenar un salto
    if(tercetoDestino == NOOP){
        printf("Ups. Parece que me olvide de rellenar un salto en los tercetos y ahora no se como seguir.\n");
        system("Pause");
        exit(10);
    }

    switch( lista_terceto[tercetoDestino].operador ){
    //case THEN:
      //  fprintf(arch, "then");
        //break;
    case ELSE:
        fprintf(arch, "else");
        break;
    case ENDIF:
        fprintf(arch, "endif");
        break;
    case WHILE:
        fprintf(arch, "while");
        break;
    case ENDWHILE:
        fprintf(arch, "endwhile");
		break;
	//case INLIST_TRUE:
      //  fprintf(arch, "inlistTrue");
		//break;
//	case INLIST_CMP:
  //      fprintf(arch, "inlistCMP");
    }

    fprintf(arch, "%d\n", tercetoDestino);
}

void asignacion(FILE* arch, int ind){
	int destino = lista_terceto[ind].op1;
	int origen = lista_terceto[ind].op2;

	//Ver tipo de dato
	switch(tabla_simbolo[destino].tipoToken){
	case INT:
		// Si es un int de tabla de simbolos, primero hay que traerlo de memoria a st(0)
		// Sino es el resultado de una expresion anterior y ya esta en st(0)
//		if(origen < OFFSET) //Es un int en tabla de simbolos
			fprintf(arch, "FILD %s\n", tabla_simbolo[origen].nombre);
//		else //El valor ya esta en el copro, puede que haga falta redondear
//			fprintf(arch, "FSTCW CWprevio ;Guardo Control Word del copro\nOR CWprevio, 0400h ;Preparo Control Word seteando RC con redondeo hacia abajo\nFLDCW CWprevio ;Cargo nueva Control Word\n");
		fprintf(arch, "FISTP %s", tabla_simbolo[destino].nombre);
		break;
	case FLOAT:
		// Si es un float de tabla de simbolos, primero hay que traerlo de memoria a st(0)
		// Sino es el resultado de una expresion anterior y ya esta en st(0)
	//	if(origen < OFFSET) //Es un float en tabla de simbolos
			fprintf(arch, "FLD %s\n", tabla_simbolo[origen].nombre);
		fprintf(arch, "FSTP %s", tabla_simbolo[destino].nombre);
		break;
	case STRING:
		//destino y origen son entradas a tabla de simbolos
		//Cargo direccion del origen y pongo esa direccion en la variable en memoria. La variable sera puntero a string.
		fprintf(arch, "LEA EAX, %s\nMOV %s, EAX", tabla_simbolo[origen].nombre, tabla_simbolo[destino].nombre);
	}

	fprintf(arch, "\n");
}

/** Levanta, da vuelta los elementos y compara */
void comparacion(FILE* arch, int ind){
	levantarEnPila(arch, ind);
	fprintf(arch, "FXCH\nFCOMP\nFSTSW AX\nSAHF\n");

}
/** Levanta, suma, y deja en pila */
/*
void suma(FILE* arch, int ind){
	levantarEnPila(arch, ind);
	fprintf(arch, "FADD\n");
}
*/

void suma(FILE* arch, int ind){
	int indiceOp1;
	int indiceOp2;

	indiceOp1 = atoi(listaTercetosResultado[ind].op1);
	indiceOp2 = atoi(listaTercetosResultado[ind].op2);

	fprintf(arch, "mov al, ");
	fprintf(arch, listaTercetosResultado[indiceOp1].op2);
	fprintf(arch, "\n");
	fprintf(arch, "add al,");
	fprintf(arch, listaTercetosResultado[indiceOp2].op2);
	fprintf(arch, "\n");
	//fprintf();
	fprintf(arch,"mov ah, 9\n");
	fprintf(arch, "mov dl,");
	fprintf(arch, listaTercetosResultado[indiceOp1].op2);
	fprintf(arch, "\n");

	fprintf(arch,"add dl, 30h\n");
	fprintf(arch,"mov ah, 2\n");
 	fprintf(arch,"int 21h\n");


	//levantarEnPila(arch, ind);
//	fprintf(arch, "FADD\n");
}

/** Levanta, revisa si hay dos operadores: Si hay uno, calcula el negativo. Si hay dos, resta y deja en pila*/
/*
void resta(FILE* arch, int ind){
	if(lista_terceto[ind].op2==NOOP){
		int aux;
		if((aux = lista_terceto[ind].op1) < OFFSET){ //Es decir si está en la tabla
			switch(tabla_simbolo[aux].tipo_dato){
				case Int:
					//FILD n; Donde n es el numero integer en memoria
					fprintf(arch, "FILD %s\n", tabla_simbolo[aux].nombre);
					break;
				case Float:
					//FLD n; Donde n es el numero float en memoria
					fprintf(arch, "FLD %s\n", tabla_simbolo[aux].nombre);
					break;
				case CteInt:
					//FILD n;Donde n es el numero integer en tabla
					fprintf(arch, "FILD %s\n", tabla_simbolo[aux].nombre);
					break;
				case CteFloat:
					//FLD n;Donde n es el numero float en tabla
					fprintf(arch, "FLD %s\n", tabla_simbolo[aux].nombre);
					break;
			}
		}
		fprintf(arch, "FCHS\n");
	}
	else{
		levantarEnPila(arch, ind);
		fprintf(arch, "FSUB\n");
	}
}*/


/** Levanta, multiplica, y deja en pila */
void multiplicacion(FILE* arch, int ind){
	levantarEnPila(arch, ind);
	fprintf(arch, "FMUL\n");
}
/** Levanta, divide, si la cuenta era de enteros se asegura de truncar y deja en pila */
void division(FILE* arch, int ind){ //Mañana reviso, seguro acá distinguimos operación integer de flotante
	levantarEnPila(arch, ind);
	fprintf(arch, "FDIV\n");
}

/** Asegura que el elemento de la izquierda esté en st1, y el de la derecha en st0 */
void levantarEnPila(FILE* arch, const int ind){
	int elemIzq = lista_terceto[ind].op1;
	int elemDer = lista_terceto[ind].op2;
	
	printf("Elemento de izquierda: %d\n", elemIzq);

	printf("Elemento de derecha: %d\n", elemDer);

	int izqLevantado = 0;
	/* Si el elemento no está en pila lo levanta */
//	if(elemIzq < OFFSET){
		switch(tabla_simbolo[elemIzq].tipoToken){
		case INT:
			//FILD n; Donde n es el numero integer en memoria
			fprintf(arch, "FILD %s\n", tabla_simbolo[elemIzq].nombre);
			break;
		case FLOAT:
			//FLD n; Donde n es el numero float en memoria
			fprintf(arch, "FLD %s\n", tabla_simbolo[elemIzq].nombre);
			break;
		//case CteInt:
			//FILD n;Donde n es el numero integer en tabla
		//	fprintf(arch, "FILD %s\n", tabla_simbolo[elemIzq].nombre);
			break;
		//case CteFloat:
			//FLD n;Donde n es el numero float en tabla
		//	fprintf(arch, "FLD %s\n", tabla_simbolo[elemIzq].nombre);
		//	break;
		}
		izqLevantado=1;
//	}
//	if(elemDer < OFFSET){
		switch(tabla_simbolo[elemDer].tipoToken){
		case INT:
			//FILD n; Donde n es el numero integer en memoria
			fprintf(arch, "FILD %s\n", tabla_simbolo[elemDer].nombre);
			break;
		case FLOAT:
			//FLD n; Donde n es el numero float en memoria
			fprintf(arch, "FLD %s\n", tabla_simbolo[elemDer].nombre);
			break;
	/*
		case CteInt:
			//FILD n;Donde n es el numero integer en tabla
			fprintf(arch, "FILD %s\n", tabla_simbolo[elemDer].nombre);
			break;
		case CteFloat:
			//FLD n;Donde n es el numero float en tabla
			fprintf(arch, "FLD %s\n", tabla_simbolo[elemDer].nombre);
			break;
		}
		*/
		//izqLevantado=0;
	}
	//if(izqLevantado){
	//	fprintf(arch, "FXCH\n");
	//}
}

void write(FILE* arch, int terceto) {
	int ind = lista_terceto[terceto].op1; //Indice de entrada a tabla de simbolos del mensaje a mostrar
	switch(tabla_simbolo[ind].tipoToken){
	case INT:
		fprintf(arch, "DisplayInteger %s\n", tabla_simbolo[ind].nombre);
		fprintf(arch, "displayString NEW_LINE\n");
		break;
	case FLOAT:
		fprintf(arch, "DisplayFloat %s,2\n", tabla_simbolo[ind].nombre);
		fprintf(arch, "displayString NEW_LINE\n");
		break;
	case STRING:
		fprintf(arch, "MOV EBX, %s\ndisplayString [EBX]\n", tabla_simbolo[ind].nombre);
		fprintf(arch, "displayString NEW_LINE\n");
		break;
		/*
	case CteString:
		fprintf(arch, "displayString %s\n", tabla_simbolo[ind].nombre);
		fprintf(arch, "displayString NEW_LINE\n");
		break;*/
	}
	fprintf(arch, "\n");
}

void read(FILE* arch, int terceto){
	int ind = lista_terceto[terceto].op1;
	switch(tabla_simbolo[ind].tipoToken){
	case INT:
		fprintf(arch, "getInteger %s\n", tabla_simbolo[ind].nombre);

		break;
	case FLOAT:
		fprintf(arch, "getFloat %s\n", tabla_simbolo[ind].nombre);

		break;
	case STRING:
		fprintf(arch, "getString %s\n", tabla_simbolo[ind].nombre);

	}
	fprintf(arch, "\n");
}

int devolverNumeroTipo(char const *tipo){
	if(strcmp(tipo, "INT                ")==0){
        return INT;
    }
	return -1;
}
