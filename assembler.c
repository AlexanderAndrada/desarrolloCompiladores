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
      //case ASIG:
	  	//asignacion(arch, i);
        //break;
    //  case CMP:
	//	comparacion(arch, i);
      //  break;
	  case MAYOR:
	  	armarComparacion(arch, i);
		break;
	  case MENOR:
	  	armarComparacion(arch, i);
		break;		
	  case IGUAL:
	  	armarComparacion(arch, i);
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
        armarFinSeccion(arch, lista_terceto[i].op1);
        break;

   //   case THEN:
     //   escribirEtiqueta(arch, "then", i);
       // break;
      case ELSE:
        //escribirEtiqueta(arch, "else", i);
        fprintf(arch, "false:\n");
        break;
      case ENDIF:
        //escribirEtiqueta(arch, "endif", i);
        armarFinSeccion(arch,lista_terceto[i].op1);
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
      case RESTA:
		resta(arch,i);
        break;
    //  case MULTIPLICACION: ARMAR EN UN RATO
	//	multiplicacion(arch,i);
      //  break;
    //  case DIVISION: ARMAR EN UN RATO
	//	division(arch,i);
      //  break;

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

    for(int i=0; i<=fin_tabla; i++){
        fprintf(arch, "%s ", tabla_simbolo[i].nombre);

        switch(tabla_simbolo[i].tipoToken){
        case INT:
            //fprintf(arch, "db %d\n", tabla_simbolo[i].valor);
			fprintf(arch, "db %d\n", 2); //Cambiar tipo
            break;
        case FLOAT:
            //fprintf(arch, "dd %f\n", tabla_simbolo[i].valor);
			fprintf(arch, "dd %s\n", "5");
            break;
        case STRING:
            //fprintf(arch, "db \"%s\", '$'\n", tabla_simbolo[i].valor);
			fprintf(arch, "db \"%s\", '$'\n", "es igual");
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
   //     printf("Ups. Parece que me olvide de rellenar un salto en los tercetos y ahora no se como seguir.\n");
   //     system("Pause");
   //     exit(10);
    }

    switch( lista_terceto[tercetoDestino].operador ){

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
    }

    fprintf(arch, "%d\n", tercetoDestino);
}

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
	
	fprintf(arch,"mov ah, 9\n");
	fprintf(arch, "mov dl,");
	//fprintf(arch, listaTercetosResultado[indiceOp1].op2);
    fprintf(arch, "al");
	fprintf(arch, "\n");

	fprintf(arch,"add dl, 30h\n");
	fprintf(arch,"mov ah, 2\n");
 	fprintf(arch,"int 21h\n");

}


void resta(FILE* arch, int ind){
	int indiceOp1;
	int indiceOp2;

	indiceOp1 = atoi(listaTercetosResultado[ind].op1);
	indiceOp2 = atoi(listaTercetosResultado[ind].op2);

	fprintf(arch, "mov al, ");
	fprintf(arch, listaTercetosResultado[indiceOp1].op2);
	fprintf(arch, "\n");
	fprintf(arch, "sub al,");
	fprintf(arch, listaTercetosResultado[indiceOp2].op2);
	fprintf(arch, "\n");
	
	fprintf(arch,"mov ah, 9\n");
	fprintf(arch, "mov dl,");
	//fprintf(arch, listaTercetosResultado[indiceOp1].op2);
    fprintf(arch, "al");
	fprintf(arch, "\n");

	fprintf(arch,"add dl, 30h\n");
	fprintf(arch,"mov ah, 2\n");
 	fprintf(arch,"int 21h\n");

}

void multiplicacion(FILE* arch, int ind){
	int indiceOp1;
	int indiceOp2;

	indiceOp1 = atoi(listaTercetosResultado[ind].op1);
	indiceOp2 = atoi(listaTercetosResultado[ind].op2);

	fprintf(arch, "mov al, ");
	fprintf(arch, listaTercetosResultado[indiceOp1].op2);
	fprintf(arch, "\n");
	fprintf(arch, "mul ");
	fprintf(arch, listaTercetosResultado[indiceOp2].op2);
	fprintf(arch, "\n");
	
	fprintf(arch,"mov ah, 9\n");
	fprintf(arch, "mov dl,");
	//fprintf(arch, listaTercetosResultado[indiceOp1].op2);
    fprintf(arch, "al");
	fprintf(arch, "\n");

	fprintf(arch,"add dl, 30h\n");
	fprintf(arch,"mov ah, 2\n");
 	fprintf(arch,"int 21h\n");

}

void division(FILE* arch, int ind){
	int indiceOp1;
	int indiceOp2;

	indiceOp1 = atoi(listaTercetosResultado[ind].op1);
	indiceOp2 = atoi(listaTercetosResultado[ind].op2);

	fprintf(arch, "mov al, ");
	fprintf(arch, listaTercetosResultado[indiceOp1].op2);
	fprintf(arch, "\n");
	fprintf(arch, "div ");
	fprintf(arch, listaTercetosResultado[indiceOp2].op2);
	fprintf(arch, "\n");
	
	fprintf(arch,"mov ah, 9\n");
	fprintf(arch, "mov dl,");
	//fprintf(arch, listaTercetosResultado[indiceOp1].op2);
    fprintf(arch, "al");
	fprintf(arch, "\n");

	fprintf(arch,"add dl, 30h\n");
	fprintf(arch,"mov ah, 2\n");
 	fprintf(arch,"int 21h\n");

}

int devolverNumeroTipo(char const *tipo){
	if(strcmp(tipo, "INT                ")==0){
        return INT;
    }
	if(strcmp(tipo, "FLOAT              ")==0){
        return FLOAT;
    }

	if(strcmp(tipo, "STRING             ")==0){
        return STRING;
    }
	return -1;
}

void armarComparacion(FILE* arch, int ind){
	
	int indiceOp1;
	int indiceOp2;

	indiceOp1 = atoi(listaTercetosResultado[ind].op1);
	indiceOp2 = atoi(listaTercetosResultado[ind].op2);

	fprintf(arch, "mov al, ");
	fprintf(arch, listaTercetosResultado[indiceOp1].op2);
	fprintf(arch, "\n");
	fprintf(arch, "CMP ");
	fprintf(arch, "al, ");
	fprintf(arch, listaTercetosResultado[indiceOp2].op2);
	fprintf(arch, "\n\n");
    fprintf(arch, "jc true\n");
	fprintf(arch, "jz false\n\n");

	fprintf(arch, "true:\n");

}

int armarFinSeccion(FILE* arch, int ind){
	fprintf(arch, ".exit\n\n");

}