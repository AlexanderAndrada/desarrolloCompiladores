#include <stdio.h>
#include <stdlib.h>
#include "assembler.h"
#include "y.tab.h"
#include "tercetos.h"
#include <ctype.h>

int ultimo_terceto;
int fin_tabla;
int hayOperacionAnterior=0;
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

int contadorDeSimbolos=0;
float numeroFloat;

    void lecturaArchivoDeSimbolos(){
        char lineaSimbolo[80]={0};
        char indiceLineaSimbolo=0;
        char caracter;
        int contadorNombre=0;
        char nombre[20]={0};
        char tipo[20]={0};
        char valor[20]={0};
        char cadenaSeparada[20]={0};
        int i,e;
        int borrar;
        int x,y,z,c;
        int indiceCopiar=0 ;
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
  escribirInicioInformacionMateria(arch);
  int i;

  for(i=0; i <= ultimo_terceto; i++){
    switch(lista_terceto[i].operador){
      case ASIG:
	  	asignacion(arch, i);
        break;
	  case MAYOR:
	  	comparacion(arch, i);
		break;
	  case MENOR:
	  	comparacion(arch, i);
		break;
	  case IGUAL:
	  	comparacion(arch, i);
		break;
      case JNA:
        escribirSalto(arch, "JNA", lista_terceto[i].op2);
        break;
      case JNBE:
        escribirSalto(arch, "JNBE", lista_terceto[i].op2);
        break;
      case JNAE:
        escribirSalto(arch, "JNAE", lista_terceto[i].op2);
        break;
      case JNB:
        escribirSalto(arch, "JNB", lista_terceto[i].op2);
        break;
      case JNE:
        escribirSalto(arch, "JNE", lista_terceto[i].op2);
        break;
      case JE:
        escribirSalto(arch, "JE", lista_terceto[i].op2);
        break;
      case JMP:
        escribirSalto(arch, "JMP", lista_terceto[i].op2);
        break; 

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
      case SUMA:
		suma(arch,i);
        break;
      case RESTA:
		resta(arch,i);
        break;
      case MULTIPLICACION:
		    multiplicacion(arch,i);
        break;
      case DIVISION:
		division(arch,i);
        break;
      case GET: 
        read(arch,i);
        break;
      case PUT:
	  	write(arch, i);
        break;
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

void escribirInicioInformacionMateria(FILE* arch){
    fprintf(arch, "lea dx,_universidad\n mov ah,09h\n int 21h\n\n");
    fprintf(arch, "lea dx,_materia\n mov ah,09h\n int 21h\n\n");
    fprintf(arch, "lea dx,_integrantes\n mov ah,09h\n int 21h\n\n");
}

void escribirFinal(FILE *arch){
    fprintf(arch, "\nMOV AH, 1\nINT 21h\nMOV AX, 4C00h\nINT 21h\n\nEND MAIN\n");
}

void generarTabla(FILE *arch){
    fprintf(arch, ".DATA\n");
    
    int i;

    fprintf(arch,"_integrantes        db 13,10,'Grupo 3: Andrada Alexander - Pirovano Pablo',13,10,'$'\n");
    fprintf(arch,"_universidad        db 13,10,'Universidad Nacional del Oeste',13,10,'$'\n");
    fprintf(arch,"_materia            db 13,10,'Desarrollo de Compiladores',13,10,'$'\n");


    for(i=0; i<=fin_tabla; i++){
        fprintf(arch, "%s ", tabla_simbolo[i].nombre);

        switch(tabla_simbolo[i].tipoToken){
        case INT:
			fprintf(arch, "dd %d\n", devolverValorEntero(tabla_simbolo[i].nombre));
            break;
        case FLOAT:
            devolverValorFloat(tabla_simbolo[i].nombre);
			fprintf(arch, "dd %.2f\n", numeroFloat);
            break;
        case STRING:
            fprintf(arch, "db 13,10,\"%s\",13,10, '$'\n", tabla_simbolo[i].valor);
            break;
        default:
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
    levantarEnPila(arch, ind);
    fprintf(arch, "FADD\n");
    hayOperacionAnterior = 1;
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


    hayOperacionAnterior = 1;
}

void multiplicacion(FILE* arch, int ind){

    levantarEnPila(arch, ind);
    fprintf(arch, "FMUL\n");
    hayOperacionAnterior = 1;

}

void division(FILE* arch, int ind){

    levantarEnPila(arch, ind);
    fprintf(arch, "FDIV\n");
    hayOperacionAnterior = 1;
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

int armarFinSeccion(FILE* arch, int ind){
	fprintf(arch, ".exit\n\n");

}

/** Asegura que el elemento de la izquierda esté en st1, y el de la derecha en st0 */
void levantarEnPila(FILE* arch, const int ind){
	int elemIzq = lista_terceto[ind].op1;
	int elemDer = lista_terceto[ind].op2;
	int izqLevantado = 0;
	/* Si el elemento no está en pila lo levanta */
	if(elemIzq < maximoTercetos){
		switch(tabla_simbolo[elemIzq].tipoToken){
		case INT:
			fprintf(arch, "FILD %s\n", tabla_simbolo[elemIzq].nombre);
			break;
		case FLOAT:
			fprintf(arch, "FLD %s\n", tabla_simbolo[elemIzq].nombre);
			break;
		}
		izqLevantado = 1;
	}
	if(elemDer < maximoTercetos){
		switch(tabla_simbolo[elemDer].tipoToken){
		case INT:
			fprintf(arch, "FILD %s\n", tabla_simbolo[elemDer].nombre);
			break;
		case FLOAT:
			fprintf(arch, "FLD %s\n", tabla_simbolo[elemDer].nombre);
			break;
		}
		izqLevantado = 0;
	}
	if(izqLevantado){
		fprintf(arch, "FXCH\n");
	}
}


/** Levanta, da vuelta los elementos y compara */
void comparacion(FILE* arch, int ind){	
    levantarEnPilaInvertida(arch, ind);
	fprintf(arch, "FXCH\nFCOMP\nFSTSW AX\nSAHF\n");
}

void asignacion(FILE* arch, int ind){
	int origen = lista_terceto[ind].op2;
	int destino = lista_terceto[ind].op2;

	switch(tabla_simbolo[destino].tipoToken){
	case INT:
        if(hayOperacionAnterior == 0)
		    fprintf(arch, "FILD %s\n", tabla_simbolo[origen].nombre);

        fprintf(arch, "FISTP %s\n", tabla_simbolo[destino].nombre);
        hayOperacionAnterior = 0;
		break;
	case FLOAT:
        if(hayOperacionAnterior == 0)
		    fprintf(arch, "FLD %s\n", tabla_simbolo[origen].nombre);
		fprintf(arch, "FISTP %s", tabla_simbolo[destino].nombre);
        hayOperacionAnterior = 0;
		break;
	case STRING:
		fprintf(arch, "LEA EAX, %s\nMOV %s, EAX", tabla_simbolo[origen].nombre, tabla_simbolo[destino].nombre);
	}

	fprintf(arch, "\n");
}

void write(FILE* arch, int terceto){

	int ind = lista_terceto[terceto].op2; //Indice de entrada a tabla de simbolos del mensaje a mostrar
    char nombreSinEspacios[20];

	switch(tabla_simbolo[ind].tipoToken){
	case INT:
		fprintf(arch, "DisplayInteger %s\n", tabla_simbolo[ind].nombre);
		break;
	case FLOAT:
        eliminarEspaciosEnBlanco(ind, nombreSinEspacios);
        fprintf(arch, "DisplayFloat %s,2\n", nombreSinEspacios);
		break;
	case STRING:
		fprintf(arch, "displayString %s\n", tabla_simbolo[ind].nombre);
		break;
	}
	fprintf(arch, "\n");
}


/** Asegura que el elemento de la izquierda esté en st1, y el de la derecha en st0 */
void levantarEnPilaInvertida(FILE* arch, const int ind){
     
    int elemIzq = posicionTablaSimbolosAssembler(listaTercetosResultado[lista_terceto[ind].op2].op2);
    int elemDer = posicionTablaSimbolosAssembler(listaTercetosResultado[lista_terceto[ind].op1].op2);

	int izqLevantado = 0;

	if(elemIzq < maximoTercetos){
		switch(tabla_simbolo[elemIzq].tipoToken){
		case INT:
			//FILD n; Donde n es el numero integer en memoria
			fprintf(arch, "FILD %s\n", tabla_simbolo[elemIzq].nombre);
			break;
		case FLOAT:
			//FLD n; Donde n es el numero float en memoria
			fprintf(arch, "FLD %s\n", tabla_simbolo[elemIzq].nombre);
			break;
		}
		izqLevantado=1;
	}
	if(elemDer < maximoTercetos){
		switch(tabla_simbolo[elemDer].tipoToken){
		case INT:
			fprintf(arch, "FILD %s\n", tabla_simbolo[elemDer].nombre);
			break;
		case FLOAT:
			//FLD n; Donde n es el numero float en memoria
			fprintf(arch, "FLD %s\n", tabla_simbolo[elemDer].nombre);
			break;
		}
		izqLevantado=0;
	}
	if(izqLevantado){
		fprintf(arch, "FXCH\n");
	}
}

   int devolverValorEntero(char* identificadorNombre){

        char valorDevInt[20]={0};
        int i;
        int x = 0;
        char vacio = '  ';

        for(i=1; i< 19;i++){
            if(isdigit(identificadorNombre[i]) != 0){ // si es 0  no es un numero
                valorDevInt[x] = identificadorNombre[i];
                x++;
            }else{
                break;
            }
        }

        if(strlen(valorDevInt) < 1){
            return 0;
        }
        else{
            return atoi(valorDevInt);
        }
	}


    int posicionTablaSimbolosAssembler(char const *cadena){
        int i,x,e;
        char auxiliar[80]={0};
        int contadorNombreAuxiliar=0;

      //  strcat(auxiliar, cadena);
        
        for(e=0;e<20;e++){
            if(cadena[e] != ' '){
                if(cadena[e] == '.'){
                    auxiliar[e] = 'p';
                }else{
                    auxiliar[e] = cadena[e];
                }
            }else{
                break;
            }
        }



         for(i=0; i<contadorDeSimbolos; i++){

             char nombreAuxiliar[80]={0};

             for(x=0; x< strlen(tabla_simbolo[i].nombre);x++){

                if(tabla_simbolo[i].nombre[x] != ' '){
                    
                    nombreAuxiliar[contadorNombreAuxiliar] = tabla_simbolo[i].nombre[x];


                    contadorNombreAuxiliar++;
                }
             }
             contadorNombreAuxiliar=0;
                printf("El auxiliar tiene: %s\n",auxiliar);
                printf("El nombre auxiliar tiene: %s\n",nombreAuxiliar);
             if(strcmp(auxiliar, nombreAuxiliar)==0){
                 return i;
             }
         }
        return -1;
    }


    void devolverValorFloat(char* identificadorNombre){

        char valorDevInt[20]={0};
        int i;
        int x = 0;
        char vacio = '  ';
        int limiteCantidadPunto = 1;
        int contadorPunto=0;

        for(i=1; i< 19;i++){
            if(isdigit(identificadorNombre[i]) != 0){ // si es 0  no es un numero
                valorDevInt[x] = identificadorNombre[i];
                x++;
            }else{
                if(identificadorNombre[i] == 'p' && contadorPunto <1){
                    contadorPunto++;
                    valorDevInt[x] = '.';
                    x++;
                }else{
                    break;
                }
                
            }
        }
        if(strlen(valorDevInt) < 1){
            numeroFloat = 0.00;
        }
        else{
            printf("Convierte esto: %s\n", valorDevInt);
            numeroFloat = atof(valorDevInt);
        }
	}

    void eliminarEspaciosEnBlanco(int indice, char *cadenaResultado){
        int e = 0;
        char caracter;

        for(e = 0; e < 20; e++){
            caracter = tabla_simbolo[indice].nombre[e];
            if(caracter != ' '){
                cadenaResultado[e]=caracter;
            }
            else{
                cadenaResultado[e]= '\0';
                break;
            }
        }
    }

    void read(FILE* arch, int terceto){
	int ind = lista_terceto[terceto].op2;

	switch(tabla_simbolo[ind].tipoToken){
	case INT:
		fprintf(arch, "getInteger %s\n", tabla_simbolo[ind].nombre);
		break;
	case FLOAT:
		fprintf(arch, "getFloat %s\n", tabla_simbolo[ind].nombre);
        fprintf(arch, "DisplayFloat %s,2\n", tabla_simbolo[ind].nombre);
		break;
	case STRING:
		fprintf(arch, "getString %s\n", tabla_simbolo[ind].nombre);
	}
	fprintf(arch, "\n");
    }