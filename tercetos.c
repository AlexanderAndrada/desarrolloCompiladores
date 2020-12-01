#include <stdio.h>
#include <stdlib.h>
#include "tercetos.h"
#include "y.tab.h"

//#include "analizadorLexico.y"
int ultimoTerceto;
int maxTercetos = 100;
int maxTabla = 100;
int cantidadDeSimbolos=0;
FILE *archivoSimbolos;


struct tercetoResultado{
	char operador[20];
	char op1[20];
	char op2[20];
}listaTercetosResultado[100]={0};

struct terceto{
	int operador;
	int op1;
	int op2;
}listaTercetos[100]={0};

  struct tablaSimbolos
  {
      char nombre[20];
      char tipo[20];
      char valor[20];
      int longitud;
	  int tipoToken;
  } tablaSimbolos[100]={0};


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
		//	printf("Es distinto de null");
		}



        while((caracter = fgetc(archivoSimbolos)) != EOF){

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
	close(archivoSimbolos);
    }


int buscar_terceto(int var, int tope){
    int i=0;
    int b=0;
    while (i<tope&&b==0){
        if(listaTercetos[i].op2==var)
            b=1;
        else i++;
    }
    if(b==1)
        return i;
    else{
        printf("Error: La variable no fue inicializada\n");
		system("Pause");
		exit(3);
    }
}

/** Agrega un terceto a la lista de tercetos. Si se quiere guardar solo una constante o variable, mandar NOOP en
el campo de operador y op2. Para los operadores pasar el token literal, para los operandos pasar la posicion en
tablaSimbolos de simbolos o el indice de otro terceto. */
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


	void escribirTablaSimbolos(){
	    int i,x, indiceRegistro,posCero=0, posVeinte=20, posCuarentena=40, posSesenta=60;
	    char registroTabla[80]={0};
	    char longitudChar[20]={0};

        FILE* archivoTablaSimbolos = fopen("tablaSimbolos.txt", "w+");

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
           }
           else{
                for(indiceRegistro=0; indiceRegistro<strlen(longitudChar); indiceRegistro++){

                    registroTabla[posSesenta]= longitudChar[indiceRegistro];
                    posSesenta++;
               }
           }

           fprintf(archivoTablaSimbolos, registroTabla);
           fprintf(archivoTablaSimbolos, "\n");


           posCero=0;
           posVeinte=20;
           posCuarentena=40;
           posSesenta=60;
	    }
        close(archivoTablaSimbolos);
	}


// Funcion para buscar una variable dentro de la tabla
// de simbolos

   int buscarPosicionTablaSimbolos(char const *cadena){
        int i,x;
        char auxiliar[80]={0};
        int contadorNombreAuxiliar=0;
        strcat(auxiliar, "_");
        strcat(auxiliar, cadena);

         for(i=0; i<cantidadDeSimbolos; i++){

             char nombreAuxiliar[80]={0};

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

//Agregar una variable a la tabla de simbolos

void agregarVariableATablaDeSimbolos(char* nombre, int token){

 //Se consulta si esta llena la tabla de simbolos
 if(cantidadDeSimbolos >= maxTabla - 1){
	 printf("Sin espacio en tabla de simbolos.\n");
	 system("Pause");
	 exit(2);
 }

 // La funcion buscar devuelve -1 si no existe otro registor con
 // ese nombre
 if(buscarPosicionTablaSimbolos(nombre) == -1){
	 //Agregar a tabla
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

	case INT:
		  strcpy(tablaSimbolos[cantidadDeSimbolos-1].nombre, "_");
		  strcat(tablaSimbolos[cantidadDeSimbolos-1].nombre, nombre);
		  strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "INT");
		  strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
		 break;

	case FLOAT:
		  strcpy(tablaSimbolos[cantidadDeSimbolos-1].nombre, "_");
		  strcat(tablaSimbolos[cantidadDeSimbolos-1].nombre, nombre);
		  strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "FLOAT");
		  strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
		 break;

	case STRING:
		  strcpy(tablaSimbolos[cantidadDeSimbolos-1].nombre, "_");
		  strcat(tablaSimbolos[cantidadDeSimbolos-1].nombre, nombre);
		  strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "STRING");
		  strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
		 break;

	case DOUBLE:
		  strcpy(tablaSimbolos[cantidadDeSimbolos-1].nombre, "_");
		  strcat(tablaSimbolos[cantidadDeSimbolos-1].nombre, nombre);
		  strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "DOUBLE");
		  strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
		 break;

	 default:
	 	printf("Error en tipo de variable");
		 break;
	 }

 }
}

void verificarLargoString (char *token, char *token2){
    if(strlen(token)+strlen(token2)>20){
        printf("\nError: Concatenacion de cadenas muy extensas\n");
        system("Pause");
        exit(2);
    }
}

int compararTipoVariable (char const *token, char const *token2){

    int posicion, posicion2;

    posicion = buscarPosicionTablaSimbolos(token);
    posicion2 = buscarPosicionTablaSimbolos(token2);

    if(strcmp(tablaSimbolos[posicion].tipo,tablaSimbolos[posicion2].tipo)==0)
        return 1;
    else{
        printf("\nError en tipo de variable\n");
        system("Pause");
        exit(2);
    }
}

char buscarTipoVariable (char *token){

    int posicion;

    posicion = buscarPosicionTablaSimbolos(token);

    return tablaSimbolos[posicion].tipo;
}

void agregarTipoDatosVariable (char *token, int tipo){

    int posicion;

    posicion = buscarPosicionTablaSimbolos(token);

    switch (tipo)
	{
		case INT:
			strcpy(tablaSimbolos[posicion].tipo, "INT");
			break;

		case CONSTANTE:
			strcpy(tablaSimbolos[posicion].tipo, "CONSTANTE");
			break;

		case REAL:
			strcpy(tablaSimbolos[posicion].tipo, "REAL");
			break;

		case DOUBLE:
			strcpy(tablaSimbolos[posicion].tipo, "DOUBLE");
			break;

		case FLOAT:
			strcpy(tablaSimbolos[posicion].tipo, "FLOAT");
			break;

		case STRING:
			strcpy(tablaSimbolos[posicion].tipo, "STRING");
			break;

		case BOOLEAN:
			strcpy(tablaSimbolos[posicion].tipo, "BOOLEAN");
			break;

		default:
			printf("\nError en tipo de variable");
			system("Pause");
            exit(2);
	}
}

int cambiarComparador (int comp){
    switch(comp){
    case MAYOR:
        return JNBE;
    case MENOR:
        return JNAE;
    case MAYORIGUAL:
        return JNB;
    case MENORIGUAL:
        return JNA;
    case IGUAL:
        return JNE;
    case DISTINTO:
        return JE;
    }
}


/** Modifica el terceto con el indice indicado en la posicion indicada. El indice debe ser sin el OFFSET
y la posicion debe ser OP1, OP2 u OPERADOR. Si el terceto no existe, aborta la compilacion. */

void modificarTerceto(int indice, int posicion, int valor){
	if(indice > ultimoTerceto -1){
		printf("Ups, algo fallo. Intente modificar un terceto que no existe. Mala mia.");
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

/* Guarda los tercetos generados en un archivo */

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

	for( i = 0; i < ultimoTerceto; i++){
		//La forma es [i] (operador, op1, op2)
		//Escribo indice
		fprintf(arch, "[%d] ( ", i);

		//escribo operador
		switch(listaTercetos[i].operador){
		case NOOP:
			fprintf(arch, "_");
			strcpy(listaTercetosResultado[i].operador,"_");
			break;
		case ASIGESPMAS:
			fprintf(arch, "+=");
			strcpy(listaTercetosResultado[i].operador,"+=");
			break;
        case ASIGESPMENOS:
			fprintf(arch, "-=");
			strcpy(listaTercetosResultado[i].operador,"-=");
            break;
        case ASIGESPMULTIPLICACION:
			fprintf(arch, "*=");
			strcpy(listaTercetosResultado[i].operador,"*=");
            break;
        case ASIGESPDIVISION:
			fprintf(arch, "/=");
			strcpy(listaTercetosResultado[i].operador,"/=");
			break;
		case BLOQ:
			fprintf(arch, "sentencia");
			strcpy(listaTercetosResultado[i].operador,"sentencia");
			break;
		case MAIN:
			fprintf(arch, "main");
			strcpy(listaTercetosResultado[i].operador,"main");
			break;
		case IDENTIFICADOR:
			fprintf(arch, "identificador");
			strcpy(listaTercetosResultado[i].operador,"identificador");
			break;
		case PUT:
			fprintf(arch, "put");
			break;
		case GET:
			fprintf(arch, "get");
			break;
		case IF:
			fprintf(arch, "if");
			break;
		case TRUE:
			fprintf(arch, "cuerpoIf");
			break;
        case ELSE:
			fprintf(arch, "cuerpoElse");
			break;
        case ENDIF:
			fprintf(arch, "endIF");
			break;
		case WHILE:
			fprintf(arch, "comparacionWhile");
			break;
        case ENDWHILE:
			fprintf(arch, "finWhile");
			break;
        case ENDSENTENCE:
			fprintf(arch, "finSentencia");
			break;
		case ASIG:
			fprintf(arch, "=");
			break;
		case SUMA:
			fprintf(arch, "+");
			strcpy(listaTercetosResultado[i].operador,"+");
			break;
		case RESTA:
			fprintf(arch, "-");
			strcpy(listaTercetosResultado[i].operador,"-");
			break;
		case MULTIPLICACION:
			fprintf(arch, "*");
			strcpy(listaTercetosResultado[i].operador,"*");
			break;
		case DIVISION:
			fprintf(arch, "/");
			strcpy(listaTercetosResultado[i].operador,"/");
			break;
		case AND:
			fprintf(arch, "y");
			break;
		case OR:
			fprintf(arch, "o");
			break;
//		case NOT:
//			fprintf(arch, "no");
//			break;
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
		case BLT: //branch lower than
			fprintf(arch, "BLT");
			break;
		case JMP: //jump to operand
			fprintf(arch, "JMP");
			break;
        case JNA: //jump not above
			fprintf(arch, "JNA");
			break;
		case JNBE: //jump not below or equal
			fprintf(arch, "JNBE");
			break;
		case JNAE: //jump not above or equal
			fprintf(arch, "JNAE");
			break;
		case JNE: //jump not equal
			fprintf(arch, "JNE");
			break;
		case JE: //jump equal
			fprintf(arch, "JE");
			break;
		case JNB: //jump not below
			fprintf(arch, "JNB");
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
			fprintf(arch, "algo esta mal");
			break;
		}

		fprintf(arch, " , ");

		//Escribo op1, el SEGUNDO PARAMETRO
		int op = listaTercetos[i].op1;

		if(op == NOOP){
			fprintf(arch, "_");
			strcpy(listaTercetosResultado[i].op1,"_");
		}
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
			//fprintf(arch, "%s", &(tablaSimbolos[op].nombre) );
			//fprintf(arch, "%s", nombreCopiar );			int i = 247593;
			char str[3];

     		sprintf(str, "%d", op);

			fprintf(arch, "[%d]", op );

			strcpy(listaTercetosResultado[i].op1,str);

		}
		else //Es el indice de otro terceto
		{
			char str[3];

     		sprintf(str, "%d", op);

			fprintf(arch, "[%d]", op );

			strcpy(listaTercetosResultado[i].op1,str);

		}
		fprintf(arch, " , ");

		//Escribo op2 TERCER PARAMETRO

		op = listaTercetos[i].op2;
		if(op == NOOP){
			fprintf(arch, "_");
			strcpy(listaTercetosResultado[i].op2,"_");
		}
		else if(op < maxTabla){
			//Es una entrada a tablaSimbolos de simbolos
				char nombreCopiar[20]={0};
			int indiceLimpioSimbolo=1;

			nombreCopiar[0]='_';
			for(o=1; o< strlen(tablaSimbolos[op].nombre); o++){
				if(tablaSimbolos[op].nombre[o] != ' '){
					nombreCopiar[indiceLimpioSimbolo] = tablaSimbolos[op].nombre[o];
					indiceLimpioSimbolo++;
				}
			}
			indiceLimpioSimbolo=0;

		if(listaTercetos[i].operador == NOOP && listaTercetos[i].op1 == NOOP){
			fprintf(arch, "%s", nombreCopiar );
			strcpy(listaTercetosResultado[i].op2,nombreCopiar);
		}
		else{

			char str[3];

     		sprintf(str, "%d", op);

			fprintf(arch, "[%d]", op );

			strcpy(listaTercetosResultado[i].op2,str);
		}
		}
		else{

			char str[3];

     		sprintf(str, "%d", op);

			fprintf(arch, "[%d]", op );

			strcpy(listaTercetosResultado[i].op2,str);
		}
		fprintf(arch, " )\n");
	}
	fclose(arch);
}

void agregarConstanteTablaDeSimbolos(char* const nombre, int token){

	int posicion;
	//Se consulta si esta llena la tabla de simbolos
	if(cantidadDeSimbolos >= maxTabla - 1){
		printf("Sin espacio en tabla de simbolos.\n");
		system("Pause");
		exit(2);
	}

	posicion = buscarPosicionTablaSimbolos(nombre);

	if(posicion == -1){

		cantidadDeSimbolos++;

		strcpy(tablaSimbolos[cantidadDeSimbolos-1].nombre, "_");
		strcat(tablaSimbolos[cantidadDeSimbolos-1].nombre, nombre);

	switch (token)
	{
		case INT:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "INT");
			tablaSimbolos[cantidadDeSimbolos - 1].tipoToken = token;
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		case CONSTANTE:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "CONSTANTE");
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			tablaSimbolos[cantidadDeSimbolos - 1].tipoToken = token;
			break;

		case REAL:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "REAL");
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			tablaSimbolos[cantidadDeSimbolos - 1].tipoToken = token;
			break;

		case DOUBLE:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "DOUBLE");
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			tablaSimbolos[cantidadDeSimbolos - 1].tipoToken = token;
			break;

		case FLOAT:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "FLOAT");
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			tablaSimbolos[cantidadDeSimbolos - 1].tipoToken = token;
			break;

		case STRING:
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].tipo, "STRING");
			strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			tablaSimbolos[cantidadDeSimbolos - 1].tipoToken = token;
			break;

		default:
			printf("Error en tipo de variable");
			break;
	}

	}
	else{
		printf("La variable ya existe");
		exit(1);
	}
}

/*
Descripcion:
			Funcion para agregar el nombre a una variable, previamente
			debe estar el tipo declarado

Parametros:
			* Nombre: contiene la variable o constante a introducir a la
			  tabla de simbolos.
*/

int agregarNombreTablaDeSimbolos(int posicionEscritura, char* nombre){

	int posicion;
	//Se consulta si esta llena la tabla de simbolos
	if(cantidadDeSimbolos >= maxTabla - 1){
		printf("Sin espacio en tabla de simbolos.\n");
		system("Pause");
		exit(2);
	}



	posicion = buscarPosicionTablaSimbolos(nombre);

	if(posicion == -1){

		//cantidadDeSimbolos++;

		strcpy(tablaSimbolos[posicionEscritura].nombre, "_");
		strcat(tablaSimbolos[posicionEscritura].nombre, nombre);

	}
	else{
		printf("La variable ya existe");
		exit(1);
	}
	return cantidadDeSimbolos - 1;
}

/*
Descripcion:
			Funcion que agrega el tipo a la variable en la tabla de simbolos

Parametros:
			* Cadena: numero de posicion en la tabla donde agregar el tipo
			* Token: numero que identifica el tipo
*/

int agregarTipoTablaDeSimbolos(int token){

	int posicion;
	//Se consulta si esta llena la tabla de simbolos
	if(cantidadDeSimbolos >= maxTabla - 1){
		printf("Sin espacio en tabla de simbolos.\n");
		system("Pause");
		exit(2);
	}

	switch (token)
	{
		case INT:
			strcpy(tablaSimbolos[cantidadDeSimbolos].tipo, "INT");
			tablaSimbolos[cantidadDeSimbolos].tipoToken = token;
			cantidadDeSimbolos++;
			//strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		case CONSTANTE:
			strcpy(tablaSimbolos[cantidadDeSimbolos].tipo, "CONSTANTE");
			tablaSimbolos[cantidadDeSimbolos].tipoToken = token;
			cantidadDeSimbolos++;
			//strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		case REAL:
			strcpy(tablaSimbolos[cantidadDeSimbolos].tipo, "REAL");
			tablaSimbolos[cantidadDeSimbolos].tipoToken = token;
			cantidadDeSimbolos++;
			//strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		case DOUBLE:
			strcpy(tablaSimbolos[cantidadDeSimbolos].tipo, "DOUBLE");
			tablaSimbolos[cantidadDeSimbolos].tipoToken = token;
			cantidadDeSimbolos++;
			//strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		case FLOAT:
			strcpy(tablaSimbolos[cantidadDeSimbolos].tipo, "FLOAT");
			tablaSimbolos[cantidadDeSimbolos].tipoToken = token;
			cantidadDeSimbolos++;
			//strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		case STRING:
			strcpy(tablaSimbolos[cantidadDeSimbolos].tipo, "STRING");
			tablaSimbolos[cantidadDeSimbolos].tipoToken = token;
			cantidadDeSimbolos++;
			//strcpy(tablaSimbolos[cantidadDeSimbolos-1].valor, nombre);
			break;

		default:
			printf("Error en tipo de variable");
			break;
	}

	return cantidadDeSimbolos-1;
}

/*
Descripcion:
			Funcion que responde ante la existencia o inexistencia de una
			variable o constante.

Parametros:
			* Cadena: numero que indica si existe la variable en la tabla de simbolos
			* Variable: el nombre de la variable
*/

void validarExistenciaVariable(int status, char const *variable){
	if(status == -1){
		printf("\nERROR: Falta declarar la variable %s\n", variable);
		exit(1);
	}
	return status;
}

int devolverCantidadTercetos(){
	return ultimoTerceto;
}

int devolverCantidadSimbolos(){
	return cantidadDeSimbolos;
}

struct terceto *devolverTercetos(){
	return listaTercetos;
}

struct tablaSimbolos *devolverTablaSimbolos(){
	return tablaSimbolos;
}

struct tercetoResultado *devolverTercetoResultado(){
	return listaTercetosResultado;
}
