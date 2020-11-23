include macros2.asm
include number.asm

.MODEL SMALL
.386
.STACK 200h

.DATA
_numero             db 2
_num                db 2
_resultado          db 2
 
.CODE
MAIN:

MOV AX, @DATA
MOV DS, AX

mov al, _numero
add al,_num
mov ah, 9
mov dl,_numero
add dl, 30h
mov ah, 2
int 21h

MOV AH, 1
INT 21h
MOV AX, 4C00h
INT 21h

END MAIN
