/*
Seccion de include
*/

#include <stdio.h>
#include <stdlib.h>
#include "tercetos.h"
#include "y.tab.h"

/*
Declaracion de variables
*/

int ultimoTerceto;
int maxTercetos = 50;
int maxTabla = 50;
int cantidadDeSimbolos=0;
FILE *archivoSimbolos;

/*
Estructura de la tabla de tercetos
*/

struct terceto
{
	int operador;
	int op1;
	int op2;
}listaTercetos[50]={0};

/*
Estructura de la tabla de simbolos
*/

struct tablaSimbolos
{
    char nombre[20];
    char tipo[20];
    char valor[20];
    int longitud;
} tablaSimbolos[50]={0};


/*
Descripcion:
			Funcion que lee el archivo de tabla de simbolos.

Parametros:
			* No posee
*/

void lecturaArchivo(){
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


	archivoSimbolos = fopen("tablaSimboloss.txt","r");

	if (archivoSimbolos == NULL)
    {
        printf("\nError de apertura del archivo. \n\n");
    }else{

        while((caracter = fgetc(archivoSimbolos)) != EOF){

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

						tablaSimbolos[contadorDeSimbolos].longitud = 0;
                    }else{
                        tablaSimbolos[contadorDeSimbolos].longitud = atoi(cadenaSeparada);
                    }
                    indiceCopiar = 0;
                }


				char nombreCopiar[20]={0};

                strncpy(tablaSimbolos[contadorDeSimbolos].nombre, nombre, 19);
                strncpy(tablaSimbolos[contadorDeSimbolos].tipo, tipo, 19);
                strncpy(tablaSimbolos[contadorDeSimbolos].valor, valor, 19);

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
	}
}

/*
Descripcion:
			Funcion que agrega un terceto a la lista de tercetos (struct de tipo terceto)

Casos: 
	* (+,1,1)  se realiza una operacion, como la suma de dos operandos. Para el primero ingresar 
	  el numero de token
	* (NOOP, NOOP, a) se realiza una carga de una variable o constante. Para eso se ingresa el 
	  indice donde se encuentra en la tabla de simbolos o terceto.

Parametros:
			* Operador
			* Operando 1
			* Operando 2
*/

int crear_terceto(int operador, int op1, int op2){

	//printf("\nEl operador es: %d\n", operador);
	//printf("\nEl op1 es: %d\n", op1);
	//printf("\nEl op2 es: %d\n", op2);


	ultimoTerceto++;
	if(ultimoTerceto >= maxTercetos){
		printf("Error: me quede sin espacio en para los tercetos. Optimiza tu codigo.\n");
		system("Pause");
		exit(3);
	}

	listaTercetos[ultimoTerceto-1].operador = operador;
	listaTercetos[ultimoTerceto-1].op1 = op1;
	listaTercetos[ultimoTerceto-1].op2 = op2;
	return ultimoTerceto -1;
}

/*
Descripcion:
			Funcion para escribir la tabla de simbolos en un archivo.

Parametros: 
			* No posee
*/

void escribirTablaSimbolos(){
	int i,x, indiceRegistro,posCero=0, posVeinte=20, posCuarentena=40, posSesenta=60;
	char registroTabla[80]={0};
	char longitudChar[20]={0};

    FILE* arch = fopen("tablaSimbolos.txt", "w+");

	for(i=0; i<cantidadDeSimbolos; i++){

	    for(x=0; x<80;x++){
            registroTabla[x]=' ';
	    }
	    registroTabla[79] = '\0';

        for(indiceRegistro=0; indiceRegistro<strlen(tablaSimbolos[i].nombre); indiceRegistro++){

            registroTabla[posCero]= tablaSimbolos[i].nombre[indiceRegistro];
            posCero++;
        }

        for(indiceRegistro=0; indiceRegistro<strlen(tablaSimbolos[i].tipo); indiceRegistro++){

            registroTabla[posVeinte]= tablaSimbolos[i].tipo[indiceRegistro];
            posVeinte++;
        }

        for(indiceRegistro=0; indiceRegistro<strlen(tablaSimbolos[i].valor); indiceRegistro++){

            registroTabla[posCuarentena]= tablaSimbolos[i].valor[indiceRegistro];
            posCuarentena++;
        }

        sprintf(longitudChar, "%d", tablaSimbolos[i].longitud);

        if(strcmp(longitudChar, "0")==0){
            registroTabla[posSesenta]= ' ';
        }else{
            for(indiceRegistro=0; indiceRegistro<strlen(longitudChar); indiceRegistro++){

                registroTabla[posSesenta]= longitudChar[indiceRegistro];
                posSesenta++;
            }
        }

        fprintf(arch, registroTabla);
        fprintf(arch, "\n");

        posCero=0;
        posVeinte=20;
        posCuarentena=40;
        posSesenta=60;
	}
    
	close(arch);
}

/*
Descripcion:
			Funcion para buscar una variable o constante dentro de la tabla de simbolos.

Parametros: 
			* Cadena: es una cadena de char, la cual es una variable o constante
*/

int buscarPosicionTablaSimbolos(char const *cadena){
    int i,x;
    char auxiliar[80]={0};
    int contadorNombreAuxiliar=0;


    for(i=0; i<cantidadDeSimbolos; i++){
        
		char auxiliar[80]={0};
        char nombreAuxiliar[80]={0};

        strcat(auxiliar, "_");
        strcat(auxiliar, cadena);

        for(x=0; x< strlen(tablaSimbolos[i].nombre);x++){

            if(tablaSimbolos[i].nombre[x] != ' '){
                
				nombreAuxiliar[contadorNombreAuxiliar] = tablaSimbolos[i].nombre[x];
				contadorNombreAuxiliar++;

            }
        }
        
		contadorNombreAuxiliar=0;

        if(strcmp(auxiliar, nombreAuxiliar)==0){
            return i;
        }
    }
    
	return -1;
    
}

/*
Descripcion:
			Funcion para agregar una variable o constante dentro de la tabla 
			de simbolos

Parametros:
			* Nombre: contiene la variable o constante a introducir a la 
			  tabla de simbolos.
			* Token: se ingresa el numero de token que corresponde, esto sirve
			  para detectar y escribir el tipo del primer parametro.  
*/

void agregarVariableATablaDeSimbolos(char* nombre, int token){

	//Se consulta si esta llena la tabla de simbolos
	if(cantidadDeSimbolos >= maxTabla - 1){
		printf("Sin espacio en tabla de simbolos.\n");
		system("Pause");
		exit(2);
	}

/*  La funcion buscar devuelve -1 si no existe otro registro con
    ese nombre. Sino, agrega la variable o constante.
*/

	if(buscarPosicionTablaSimbolos(nombre) == -1){

		cantidadDeSimbolos++;
		//printf("Cantidad de simbolos: %d", cantidadDeSimbolos);

		//se empieza a ingresar los datos en la tabla de simbolos
		switch (token)
		{
		case IDENTIFICADOR:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].nombre, "_");
			strcat(tablaSimbolos[cantidadDeSimbolos-1].nombre, nombre);
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "IDENTIFICADOR");
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		case CONSTANTE:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].nombre, "_");
			strcat(tablaSimbolos[cantidadDeSimbolos-1].nombre, nombre);
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "CONSTANTE");
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		case REAL:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].nombre, "_");
			strcat(tablaSimbolos[cantidadDeSimbolos-1].nombre, nombre);
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "REAL");
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		default:
			printf("Error en tipo de variable");
			break;
		}
	}
}











/*
Descripcion:
			Funcion para agregar una variable o constante dentro de la tabla 
			de simbolos

Parametros:
			* Nombre: contiene la variable o constante a introducir a la 
			  tabla de simbolos.
			* Token: se ingresa el numero de token que corresponde, esto sirve
			  para detectar y escribir el tipo del primer parametro.  
*/

void declaracionVariableATablaDeSimbolos(char* nombre, int token){

	//Se consulta si esta llena la tabla de simbolos
	if(cantidadDeSimbolos >= maxTabla - 1){
		printf("Sin espacio en tabla de simbolos.\n");
		system("Pause");
		exit(2);
	}

/*  La funcion buscar devuelve -1 si no existe otro registro con
    ese nombre. Sino, agrega la variable o constante.
*/

	if(buscarPosicionTablaSimbolos(nombre) == -1){

		cantidadDeSimbolos++;
		//printf("Cantidad de simbolos: %d", cantidadDeSimbolos);

		//se empieza a ingresar los datos en la tabla de simbolos
		switch (token)
		{
		case IDENTIFICADOR:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].nombre, "_");
			strcat(tablaSimbolos[cantidadDeSimbolos-1].nombre, nombre);
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "IDENTIFICADOR");
			//strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		case CONSTANTE:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].nombre, "_");
			strcat(tablaSimbolos[cantidadDeSimbolos-1].nombre, nombre);
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "CONSTANTE");
			//strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		case REAL:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].nombre, "_");
			strcat(tablaSimbolos[cantidadDeSimbolos-1].nombre, nombre);
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "REAL");
			//strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		case FLOAT:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].nombre, "_");
			strcat(tablaSimbolos[cantidadDeSimbolos-1].nombre, nombre);
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "FLOAT");
			//strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;	

		default:
			printf("Error en tipo de variable");
			break;
		}
	}
}














































/*
Descripcion:
	Modifica el terceto con el indice indicado en la posicion indicada la posicion debe ser 
	OP1, OP2 u OPERADOR.
	Si el terceto no existe, aborta la compilacion.

Parametros:
			* Operando 1
			* Operando 2
			* Operador	
*/

void modificarTerceto(int indice, int posicion, int valor){

	if(indice > ultimoTerceto -1){
		printf("Indice a modificar fuera de rango, funcion modificarTerceto");
		system ("Pause");
		exit (4);
	}
	switch(posicion){
	case OP1:
		listaTercetos[indice].op1 = valor;
		break;
	case OP2:
		listaTercetos[indice].op2 = valor;
		break;
	case OPERADOR:
		listaTercetos[indice].operador = valor;
		break;
	}
}

/* 
Descripcion:
			Guarda en un archivo la lista de tercetos

Parametros:
			* Sin parametros

Formato de escritura:
			* [i] (operador, [op1], [op2])
			* [i] ( _ , _ , op2)						 
*/

void guardarArchivoTercetos(){
	int o=0;

	if(ultimoTerceto == -1)
		yyerror("No encontre los tercetos");

	FILE* arch = fopen("intermedia.txt", "w+");

	if(!arch){
		printf("No pude crear el archivo intermedia.txt\n");
		return;
	}

	int i;


	// Empieza el bucle de la lista de tercetos
	for( i = 0; i < ultimoTerceto; i++){

		// Escribe la posicion de cada terceto.
		fprintf(arch, "[%d] ( ", i);

		//Primer parametro del terceto, el cual es el operador
		switch(listaTercetos[i].operador){
		case NOOP:
			fprintf(arch, "_");
			break;
		case ASIGESPMAS:
			fprintf(arch, "+=");
			break;
		case BLOQ:
			fprintf(arch, "sentencia");
			break;
		case MAIN:
			fprintf(arch, "main");
			break;
		case IDENTIFICADOR:
			fprintf(arch, "identificador");
			break;
		case IF:
			fprintf(arch, "if");
			break;
		case ELSE:
			fprintf(arch, "cuerpoElse");
			break;
		case WHILE:
			fprintf(arch, "while");
			break;
		case ASIG:
			fprintf(arch, "=");
			break;
		case SUMA:
			fprintf(arch, "+");
			break;
		case RESTA:
			fprintf(arch, "-");
			break;
		case MULTIPLICACION:
			fprintf(arch, "*");
			break;
		case DIVISION:
			fprintf(arch, "/");
			break;
		case AND:
			fprintf(arch, "y");
			break;
		case OR:
			fprintf(arch, "o");
			break;
		case MENOR:
			fprintf(arch, "<");
			break;
		case MAYOR:
			fprintf(arch, ">");
			break;
		case MENORIGUAL:
			fprintf(arch, "<=");
			break;
		case MAYORIGUAL:
			fprintf(arch, ">=");
			break;
		case IGUAL:
			fprintf(arch, "==");
			break;
		case DISTINTO:
			fprintf(arch, "=/=");
			break;
		case PUNTOYCOMA:
			fprintf(arch, "\';\'");
			break;
		case CMP: //compare
			fprintf(arch, "CMP");
			break;
		case BNE: //branch not equal
			fprintf(arch, "BNE");
			break;
		case BEQ: //branch equal
			fprintf(arch, "BEQ");
			break;
		case BGT: //branch greater than
			fprintf(arch, "BGT");
			break;
		case BGE: //branch greater equal
			fprintf(arch, "BGE");
			break;
		case BLE: //branch lower equal
			fprintf(arch, "BLE");
			break;
		case BLT: //branch lower equal
			fprintf(arch, "BLT");
			break;
		case JMP: //jump to operand
			fprintf(arch, "JMP");
			break;
		case INL:
			fprintf(arch, "INL");
			break;
		case INOK:
			fprintf(arch, "INOK");
			break;
		case IOK:
			fprintf(arch, "IOK");
			break;
		default:
			fprintf(arch, "Error al escribir el operador");
			break;
		}

		fprintf(arch, " , ");

		//Segundo parametro del terceto, el cual es el op1
		int op = listaTercetos[i].op1;

		if(op == NOOP)
			fprintf(arch, "_");
		else if(op < maxTabla){
			//Es una entrada a tablaSimbolos de simbolos
			char nombreCopiar[20]={0};
			int indiceLimpioSimbolo=0;
			for(o=1; o< strlen(tablaSimbolos[op].nombre); o++){
				if(tablaSimbolos[op].nombre[o] != ' '){
					nombreCopiar[indiceLimpioSimbolo] = tablaSimbolos[op].nombre[o];
					indiceLimpioSimbolo++;
				}
			}
			indiceLimpioSimbolo=0;
			fprintf(arch, "[%d]", op );
		}
		else //Es el indice de otro terceto
			fprintf(arch, "[%d]", op);

		fprintf(arch, " , ");


		//Tercer parametro del terceto, el cual es el op2
		op = listaTercetos[i].op2;
		if(op == NOOP)
			fprintf(arch, "_");
		else if(op < maxTabla){
			//Es una entrada a tablaSimbolos de simbolos
				char nombreCopiar[20]={0};
			int indiceLimpioSimbolo=0;
			for(o=1; o< strlen(tablaSimbolos[op].nombre); o++){
				if(tablaSimbolos[op].nombre[o] != ' '){
					nombreCopiar[indiceLimpioSimbolo] = tablaSimbolos[op].nombre[o];
					indiceLimpioSimbolo++;
				}
			}
			indiceLimpioSimbolo=0;

		if(listaTercetos[i].operador == NOOP && listaTercetos[i].op1 == NOOP){
			fprintf(arch, "%s", nombreCopiar );
		}
		else{
			fprintf(arch, "[%d]", op );
		}
		}
		else //Es el indice de otro terceto
			fprintf(arch, "[%d]", op);

		fprintf(arch, " )\n");
	}
	fclose(arch);
}