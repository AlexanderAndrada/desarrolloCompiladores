#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>


#include "y.tab.h"

//Trae el files del analizador sintactico
extern FILE *yyin;

  struct token
  {
      int token;
      int valor;
  };

  struct tablaSimbolos
  {
      char nombre[20];
      char tipo[20];
      char valor[20];
      int longitud;
      char tuplaTotal[80];
  } tabla[50]={0};

	char identificador[20]={0};
	char constante[20]={0};
	char string[20]={0};
	char operadores[20]={0};
	char comparadores[20]={0};
	char otros[1]={0};
	char asignador[1]={0};
	char reales[20]={0};
	char asignacionesEspeciales[20]={0};
	char comentarios[20]={0};
    char bufferIdentificador[20]={0};

    int contadorLetras=0;
	int evento=0;
	int estado=0;
	int terminar=0;
	int contadorSombrero=0;
	int contadorComillas=0;
	int contadorRegistroTabla=0;
	int contadorSimbolos=0;
	int retroceder=0;
	int segundavuelta=0;
    int fin=0;
    int banderaLetra=0;
    int banderaNumero=0;
    int banderaSuma=0;
    int banderaResta=0;
    int banderaMult=0;
    int banderaDiv=0;
    int banderaAsig=0;
    int banderaMenor=0;
    int banderaMayor=0;
    int banderaNega=0;
    int banderaOR=0;
    int banderaAND=0;
    int banderaEOF=0;
    int banderaFin=0;


	struct token tokenFinal;

	char caracter;


	//yyin = fopen("programa.in","r");

	void limpiarVectores(){
	    int i;
	    for(i =0; i<20;i++){
            identificador[i]='\0';
            constante[i]='\0';
            operadores[i]='\0';
            comparadores[i]='\0';
            string[i]='\0';
            reales[i]='\0';
            asignacionesEspeciales[i]='\0';
            comentarios[i]='\0';
	    }
        otros[0]='\0';
        asignador[0]='\0';
        asignacionesEspeciales[0]='\0';
        asignacionesEspeciales[1]='\0';
	};

    void limpiarBanderas(){
        banderaLetra=0;
        banderaNumero=0;
        banderaSuma=0;
        banderaResta=0;
        banderaMult=0;
        banderaDiv=0;
        banderaAsig=0;
        banderaMenor=0;
        banderaMayor=0;
        banderaNega=0;
        banderaOR=0;
        banderaAND=0;
        contadorSombrero=0;
        contadorComillas=0;
    };

    void limpiarConstante(){
        int i;
        for(i =0; i<20;i++)
            identificador[i]='\0';
	};

	struct token obtenerToken(){
	    struct token tkn;

	    if(strlen(identificador)>0){
            if(strcmp(identificador, "IF")==0){
                tkn.token=IF;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(identificador, "ELSE")==0){
                tkn.token=ELSE;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(identificador, "WHILE")==0){
                tkn.token=WHILE;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(identificador, "MAIN")==0){
                tkn.token=MAIN;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(identificador, "INT")==0){
                tkn.token=INT;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(identificador, "FLOAT")==0){
                tkn.token=FLOAT;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(identificador, "DOUBLE")==0){
                tkn.token=DOUBLE;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(identificador, "CHAR")==0){
                tkn.token=CHAR;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(identificador, "BOOLEAN")==0){
                tkn.token=BOOLEAN;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(identificador, "GET")==0){
                tkn.token=GET;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(identificador, "PUT")==0){
                tkn.token=PUT;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(identificador, "DECLARE")==0){
                tkn.token=DECLARE;
                tkn.valor=-1;
                return tkn;
            }

	    }

	    if(strlen(constante)>0){
            tkn.token=CONSTANTE;

            strcpy(yylval.var,constante);
            tkn.valor=-1;

            strcpy(tabla[contadorRegistroTabla].nombre, "_");
            strcat(tabla[contadorRegistroTabla].nombre, constante);
            strcpy(tabla[contadorRegistroTabla].tipo,"CONSTANTE");
            strcpy(tabla[contadorRegistroTabla].valor,constante);
            tabla[contadorRegistroTabla].longitud=0;
            contadorRegistroTabla++;

            return tkn;
	    }

	    if(strlen(reales)>0){
            tkn.token=REAL;

            strcpy(yylval.var,reales);
            tkn.valor=-1;

            strcpy(tabla[contadorRegistroTabla].nombre, "_");
            strcat(tabla[contadorRegistroTabla].nombre, reales);
            strcpy(tabla[contadorRegistroTabla].tipo,"REAL");
            strcpy(tabla[contadorRegistroTabla].valor,reales);
            tabla[contadorRegistroTabla].longitud=0;
            contadorRegistroTabla++;

            return tkn;
	    }

	    if(strlen(operadores)>0){
            if(strcmp(operadores, "+")==0){
                tkn.token=SUMA;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(operadores, "-")==0){
                tkn.token=RESTA;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(operadores, "*")==0){
                tkn.token=MULTIPLICACION;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(operadores, "/")==0){
                tkn.token=DIVISION;
                tkn.valor=-1;
                return tkn;
            }
	    }

	    if(strlen(comparadores)>0){
            if(strcmp(comparadores, ">")==0){
                tkn.token=MAYOR;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(comparadores, "<")==0){
                tkn.token=MENOR;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(comparadores, "<=")==0){
                tkn.token=MENORIGUAL;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(comparadores, ">=")==0){
                tkn.token=MAYORIGUAL;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(comparadores, "==")==0){
                tkn.token=IGUAL;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(comparadores, "!=")==0){
                tkn.token=DISTINTO;
                tkn.valor=-1;
                return tkn;
            }
	    }

	    if(strlen(otros)>0){
            if(strcmp(otros, ";")==0){
                tkn.token=PUNTOYCOMA;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(otros, "(")==0){
                tkn.token=ABRIRPARENTESIS;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(otros, ")")==0){
                tkn.token=CERRARPARENTESIS;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(otros, "{")==0){
                tkn.token=ABRIRLLAVE;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(otros, "}")==0){
                tkn.token=CERRARLLAVE;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(otros, "[")==0){
                tkn.token=ABRIRCORCHETE;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(otros, "]")==0){
                tkn.token=CERRARCORCHETE;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(otros, "&&")==0){
                tkn.token=AND;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(otros, "||")==0){
                tkn.token=OR;
                tkn.valor=-1;
                return tkn;
            }
            if(strcmp(otros, "?")==0){
                tkn.token=CONCAT;
                tkn.valor=-1;
                return tkn;
            }
	    }

	    if(strlen(asignacionesEspeciales)==2){

             if(strcmp(asignacionesEspeciales, "+=")==0){
                tkn.token=ASIGESPMAS;
                tkn.valor=-1;
                return tkn;
            }

            if(strcmp(asignacionesEspeciales, "-=")==0){
                tkn.token=ASIGESPMENOS;
                tkn.valor=-1;
                return tkn;
            }

            if(strcmp(asignacionesEspeciales, "*=")==0){
                tkn.token=ASIGESPMULTIPLICACION;
                tkn.valor=-1;
                return tkn;
            }

            if(strcmp(asignacionesEspeciales, "/=")==0){
                tkn.token=ASIGESPDIVISION;
                tkn.valor=-1;
                return tkn;
            }
	    }

	    if(strlen(asignador)>0){
            if(strcmp(asignador, "=")==0){
                tkn.token=ASIG;
                tkn.valor=-1;
                return tkn;
            }
	    }

        //colocar contador de ", deben ser 2

	    if(strlen(string)>0){
            tkn.token=STRING;
            strcpy(yylval.var,string);
            tkn.valor=-1;

            strcpy(tabla[contadorRegistroTabla].nombre, "_");
            strcat(tabla[contadorRegistroTabla].nombre, string);
            strcpy(tabla[contadorRegistroTabla].tipo,"STRING");
            strcpy(tabla[contadorRegistroTabla].valor,string);
            tabla[contadorRegistroTabla].longitud=strlen(string);
            contadorRegistroTabla++;

            return tkn;
	    }

	    if(strlen(comentarios)>0){
            tkn.token=COMENTARIO;
            tkn.valor=-1;
            return tkn;
	    }

        if(strlen(identificador)>0){
            int i;
            int b;
            b=0;
            strcpy(bufferIdentificador,"_");
            strcat(bufferIdentificador, identificador);
            for(i=0;i<contadorRegistroTabla;i++){
                    if(strcmp(bufferIdentificador,tabla[i].nombre)==0)
                        b=1;
            }
            strcpy(yylval.var,identificador);
            tkn.token=IDENTIFICADOR;
            tkn.valor=-1;

            if(b==0){
                strcpy(tabla[contadorRegistroTabla].nombre, "_");
                strcat(tabla[contadorRegistroTabla].nombre, identificador);
                strcpy(tabla[contadorRegistroTabla].tipo,"IDENTIFICADOR");
                tabla[contadorRegistroTabla].longitud=0;
                contadorRegistroTabla++;
                for (i=0;i<20;i++)
                    bufferIdentificador[i]='\0';
            }
            return tkn;
        }

        tkn.token=1;
        tkn.valor=-1;

	return (tkn);
	}
    //Guarda letras

    //ESPACIO
	void f0(){
	};


    //LETRA
	void f1(){
	    banderaLetra=1;
		identificador[strlen(identificador)] = caracter;
	};

    //Guarda digitos, sin puntos
	void f2(){
        constante[strlen(constante)] = caracter;
	};

    //Guarda digitos con puntos
    void f3(){
        banderaNumero=1;
        int i;
        strcat(reales, constante);
	    for(i =0; i<20;i++){
            constante[i]='\0';
	    }
        reales[strlen(reales)]=caracter; //agregaria el punto
    };

    //Continua el numero real
    void f4(){
        reales[strlen(reales)]=caracter;
    };

    //Guarda el operador +
    void f5(){
        banderaSuma=1;
        operadores[strlen(operadores)]=caracter;
    };

    //Guarda el operador -
    void f6(){
        banderaResta=1;
        operadores[strlen(operadores)]=caracter;
    };

    //Guarda el operador *
    void f7(){
        banderaMult=1;
        operadores[strlen(operadores)]=caracter;
    };

    //Guarda el operador /
    void f8(){
        banderaDiv=1;
        operadores[strlen(operadores)]=caracter;
    };

    //Guarda el operador =
    void f9(){
        asignador[strlen(asignador)]=caracter;
    };

    //Guarda el operador +=
    void f10(){
        int i;
        strcat(asignacionesEspeciales, operadores);
        asignacionesEspeciales[strlen(asignacionesEspeciales)]=caracter;
        for(i =0; i<strlen(operadores);i++){
            operadores[i]='\0';
        }
    };

    //Guarda el operador -=
    void f11(){
        int i;
        strcat(asignacionesEspeciales, operadores);
        asignacionesEspeciales[strlen(asignacionesEspeciales)]=caracter;
        for(i =0; i<strlen(operadores);i++){
            operadores[i]='\0';
        }
    };

    //Guarda el operador *=
    void f12(){
        int i;
        strcat(asignacionesEspeciales, operadores);
        asignacionesEspeciales[strlen(asignacionesEspeciales)]=caracter;
        for(i =0; i<strlen(operadores);i++){
            operadores[i]='\0';
        }
    };

    //Guarda el operador /=
    void f13(){
        int i;
        strcat(asignacionesEspeciales, operadores);
        asignacionesEspeciales[strlen(asignacionesEspeciales)]=caracter;
        for(i =0; i<strlen(operadores);i++){
            operadores[i]='\0';
        }
    };

    //Guarda el operador ==
    void f14(){
        banderaAsig=1;
        int i;
        strcat(comparadores, asignador);
        comparadores[strlen(comparadores)]=caracter;
        for(i =0; i<strlen(asignador);i++){
            asignador[i]='\0';
        }
    };

    //Guarda {
    void f15(){
        otros[strlen(otros)]=caracter;
    };

    //Guarda }
    void f16(){
        otros[strlen(otros)]=caracter;
    };

    //Guarda (
    void f17(){
        otros[strlen(otros)]=caracter;
    };

    //Guarda )
    void f18(){
        otros[strlen(otros)]=caracter;
    };

    //Guarda [
    void f19(){
        otros[strlen(otros)]=caracter;
    };

    //Guarda ]
    void f20(){
        otros[strlen(otros)]=caracter;
    };

    //Comentarios
    void f21(){
        if(contadorSombrero==0)
            contadorSombrero++;
            else comentarios[strlen(comentarios)]=caracter;
    };

    //Strings
    void f22(){
        if(contadorComillas==0)
            contadorComillas++;
            else string[strlen(string)]=caracter;
    };

    //Guarda el comparador <
    void f23(){
        banderaMenor=1;
        comparadores[strlen(comparadores)]=caracter;
    };

    //Guarda el comparador >
    void f24(){
        banderaMayor=1;
        comparadores[strlen(comparadores)]=caracter;
    };

    //Guarda el comparador !
    void f25(){
        banderaNega=1;
        comparadores[strlen(comparadores)]=caracter;
    };

    //Guarda el comparador <=
    void f26(){
        comparadores[strlen(comparadores)]=caracter;
    };

    //Guarda el comparador >=
    void f27(){
        comparadores[strlen(comparadores)]=caracter;
    };

    //Guarda el comparador !=
    void f28(){
        comparadores[strlen(comparadores)]=caracter;
    };

    //Guardar |
    void f29(){
        otros[strlen(otros)]=caracter;
    };

    //Guardar &
    void f30(){
        otros[strlen(otros)]=caracter;
    };

    //Guardar ||
    void f31(){
        banderaOR=1;
        otros[strlen(otros)]=caracter;
    };

    //Guardar &&
    void f32(){
        banderaAND=1;
        otros[strlen(otros)]=caracter;
    };

    //Guardar ;
    void f33(){
        otros[strlen(otros)]=caracter;
    };

    //Guardar ?
    void f34(){
        otros[strlen(otros)]=caracter;
    };

    //FIN Correcto
    void f41(){
        terminar=1;
    };

    //FIN Retroceder
    void f42(){
        terminar=1;
        retroceder=1;
    };

    //FIN ERROR
    void f43(){
		exit(1);
    };

    //FIN EOF
    void f44(){
		exit(0);
    };


	int devolverEstado(char letra){
	    if(contadorComillas==1) return 22;
	    if(contadorSombrero==1) return 21;
        if(isalpha(letra)) return 1;
		if(isdigit(letra)){
                if (banderaNumero==0)
                    return 2;
                else return 4;
		}
		if(letra=='.') return 3;
		if(letra=='+') return 5;
        if(letra=='-') return 6;
        if(letra=='*') return 7;
        if(letra=='/') return 8;
		if(letra=='='){
                if(banderaSuma==1) return 10;
                if(banderaResta==1) return 11;
                if(banderaMult==1) return 12;
                if(banderaDiv==1) return 13;
                if(banderaAsig==1) return 14;
                if(banderaMenor==1) return 26;
                if(banderaMayor==1) return 27;
                if(banderaNega==1) return 28;
                return 9;
		};
        if(letra=='{') return 15;
        if(letra=='}') return 16;
		if(letra=='(') return 17;
        if(letra==')') return 18;
        if(letra=='[') return 19;
        if(letra==']') return 20;
		if(letra=='^'){
                if(contadorSombrero==2) return 34;
                else return 21;
		};
		if(letra=='\"'){
                if(contadorComillas==2) return 34;
                else return 22;
        };
		if(letra=='>') return 23;
		if(letra=='<') return 24;
		if(letra=='!') return 25;
        if(letra=='|'){
                if(banderaOR==1) return 31;
                return 29;
        };
        if(letra=='&'){
                if(banderaAND==1) return 32;
                return 30;
        };
        if(letra==';') {
            if(estado==0) return 33;
            else if(banderaNumero==1||banderaOR==1||banderaAND==1) return 36;
                else if(contadorSombrero>0) return 21;
                    else if(contadorComillas>0) return 22;
                        else return 35;
        };
        if(letra=='\n') return estado;
        if(letra=='\t') return estado;
        if(letra==' '){
                if(strlen(identificador)>0) return 35;
                else if(banderaOR==1||banderaAND==1) return 36;
                    else estado;
        };
        if(letra=='?') return 33;
        if(letra=='~') return 34;
		return 36;
    };

	int devolverEvento(char letra){
        if(isalpha(letra)) return 0;
		if(isdigit(letra)) return 1;
		if(letra=='.') return 2;
		if(letra=='+') return 3;
        if(letra=='-') return 4;
        if(letra=='*') return 5;
        if(letra=='/') return 6;
		if(letra=='=') return 7;
        if(letra=='{') return 8;
        if(letra=='}') return 9;
		if(letra=='(') return 10;
        if(letra==')') return 11;
        if(letra=='[') return 12;
        if(letra==']') return 13;
		if(letra=='^'){
                if(contadorSombrero==1) contadorSombrero++;
                return 14;
        };
		if(letra=='\"') {
                if(contadorComillas==1) contadorComillas++;
                return 15;
		};
		if(letra=='>') return 16;
		if(letra=='<') return 17;
		if(letra=='!') return 18;
        if(letra=='|') return 19;
        if(letra=='&') return 20;
        if(letra==';') return 21;
        if(letra=='\n') return 22;
        if(letra==' ') return 23;
        if(letra=='~') return 24;
        if(letra=='\t') return 26;
        if(letra=='?') return 27;
		return 25;
    };

	//Tabla
	void(*proceso[37][28])()={
    //    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27
/*0*/     f1, f2,f43, f5, f6, f7, f8, f9,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f29,f30,f33, f0, f0,f44,f43, f0,f34,
/*1*/     f1, f1,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*2*/    f43, f2, f3,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*3*/    f43, f4,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*4*/    f42, f4,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*5*/    f42,f42,f43,f42,f42,f42,f42,f10,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*6*/    f42,f42,f43,f42,f42,f42,f42,f11,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*7*/    f42,f42,f43,f42,f42,f42,f42,f12,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*8*/    f42,f42,f43,f42,f42,f42,f42,f13,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*9*/    f42,f42,f43,f42,f42,f42,f42,f14,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*10*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*11*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*12*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*13*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*14*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*15*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*16*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*17*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*18*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*19*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*20*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*21*/   f21,f21,f21,f21,f21,f21,f21,f21,f21,f21,f21,f21,f21,f21,f41,f21,f21,f21,f21,f21,f21,f21, f0, f0,f43,f21, f0,f21,
/*22*/   f22,f22,f22,f22,f22,f22,f22,f22,f22,f22,f22,f22,f22,f22,f22,f41,f22,f22,f22,f22,f22,f22, f0, f0,f43,f22, f0,f22,
/*23*/   f42,f42,f43,f42,f42,f42,f42,f26,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*24*/   f42,f42,f43,f42,f42,f42,f42,f27,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*25*/   f42,f42,f43,f42,f42,f42,f42,f28,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*26*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*27*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*28*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*29*/   f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f31,f43,f43, f0,f43,f43,f43, f0,f43,
/*30*/   f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f32,f43, f0,f43,f43,f43, f0,f43,
/*31*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*32*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*33*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42, f0, f0,f41,f43, f0,f42,
/*34*/   f41,f41,f43,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f41,f43,f41,f41,
/*35*/   f42,f42,f43,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f42,f41,f41,f42,f43,f41,f42,
/*36*/   f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f43,f41,f43,f43,f43
   	};

   	int estadoActual[10][9]={
	 //    0 1 2 3 4 5 6 7 8
/*0*/	   0,0,0,0,0,0,0,0,0,
/*1*/	   1,1,2,1,1,1,1,1,1, //
/*2*/	   2,2,2,2,2,2,2,2,2, //digito con
/*3*/	   3,3,3,4,3,3,3,3,3, // operador
/*4*/	   4,4,4,4,4,4,6,4,4,  //igual o especial
/*5*/      5,5,5,5,5,5,5,5,5,   //otros
/*6*/      6,6,6,6,6,6,6,6,6,   //comentario
/*7*/      7,7,7,7,7,7,7,7,7,     //string
/*8*/      8,8,8,8,8,8,8,8,9,     //mayor menor
/*9*/      8,8,8,8,10,8,8,8,10     //mayor menor
	   };

    int yylex(void){

        while(1){

            if(terminar==0){

                caracter = fgetc(yyin);
                if(feof(yyin)){
                    caracter='~';

                };

                evento=devolverEvento(caracter);

                (*proceso[estado][evento])();
                estado=devolverEstado(caracter);

            }
            if(terminar==1){
                if(retroceder==1){
                    fseek(yyin, -sizeof(caracter), SEEK_CUR);
                    retroceder=0;
                }
                tokenFinal=obtenerToken();
                contadorLetras=0;
                limpiarVectores();
                limpiarBanderas();
                terminar=0;
                estado=0;
                if(banderaEOF==1)
                    fseek(yyin, sizeof(caracter), SEEK_CUR);
                if(banderaEOF==1)
                    if(feof(yyin))
                        return 0;

                return tokenFinal.token;
            }
                if(feof(yyin)){
                    return 0;
        };
        }
    return 0;
    }

