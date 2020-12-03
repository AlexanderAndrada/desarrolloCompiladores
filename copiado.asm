CopiarCadena macro cadena_fuente, cadena_destino
LOCAL copiar, salir
;copia una cadena en otra.
XOR AX, AX
XOR BX, BX
    mov si,offset cadena_fuente
    mov di,offset cadena_destino
	LongitudCadena ;setea en el registro bx la longitud de la cadena.
	mov cx,bx
    copiar: 
			mov al,byte ptr [si]
			mov byte ptr[di],al
			cmp cx,0
			je salir
			inc si
			inc di
			dec cx
			jmp copiar
    salir:

    mov ax,0C07h
    int 21h
endm

; devuelve en BX la cantidad de caracteres que tiene un string
; DS:SI apunta al string.
LongitudCadena macro
LOCAL longitud, salir
	mov bx,0
longitud:
	cmp BYTE PTR [SI+BX],'$'
	je salir
	inc BX
	jmp longitud
	
salir:
endm

CopiarNumero macro numero_fuente, numero_destino
;copia un flotante en otro.
fld numero_fuente
fstp numero_destino
endm

ConcatenarCadena macro cadena_1, cadena_2, cadena_destino
LOCAL copiado1, salida1, copiado2, salida2
;Concatena dos cadenas en una tercera.
    mov si,offset cadena_1
    mov di,offset cadena_destino
	LongitudCadena ;
mov cx,bx
	
    ;mov cx,len
    copiado1: 
			mov al,byte ptr [si]
			mov byte ptr[di],al
			cmp cx,0
			je salida1
			inc si
			inc di
			dec cx
			jmp copiado1
	
    salida1:
			mov si,offset cadena_2
			LongitudCadena ;setea en el registro bx la longitud de la cadena.
			mov cx,bx
			copiado2: 
			mov al,byte ptr [si]
			mov byte ptr[di],al
			cmp cx,0
			je salida2
			inc si
			inc di
			dec cx
			jmp copiado2
	
	salida2:

    mov ax,0C07h
    int 21h
endm