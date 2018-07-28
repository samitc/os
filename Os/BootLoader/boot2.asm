[org 0x9FBFF]
 
bits 16

JMP main

%include "include/bootConsole.inc"
%include "include/GDT.inc"
%include "include/A20.inc"
%include "include/NMI.inc"
 
;*************************************************;
;	Second Stage Loader Entry Point
;************************************************;
 
main:
	MOV AX,42
	CALL printNum
	CALL checkA20
	CALL printReg
	MOV AL,0x20
	CALL printNum
	CALL prepeareA20
	CALL checkA20
	CALL printReg
	cli		; clear interrupts to prevent triple faults
	CALL disableNMI
	CALL loadGdt
	JMP enterPMode

enterPMode:
	CLI
	XOR AX,AX
        MOV BX,0X9000
        MOV DS,AX
        ;MOV SS,BX
        MOV ES,AX
        ;MOV SP,0XFFFF;need to check the value.why it is this number
	;MOV AX,9
	;MOV CS,AX
	JMP 9:$-90
	MOV AX,CS
	CALL printReg
	MOV EAX,CR0
	OR EAX,1
	MOV CR0,EAX
	JMP 8:stage3

bits 32

stage3:
int 19
	MOV AL,50
lop1:
        MOV [EBX],AL
        ADD EBX,2
LOOP lop1
	MOV EBX,0xf0000
	MOV AX,0x10
	MOV DS,AX
	MOV ESP,0X90000;need to check the value.why it is this number
	MOV SS,AX
	MOV ES,AX
	MOV EBX,0xB8000
	MOV AL,65
	MOV CX,100
lop:
	MOV [EBX],AL
	ADD EBX,2
LOOP lop
	JMP $
	CLI
	HLT
