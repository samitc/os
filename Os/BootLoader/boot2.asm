[org 0x6600]
 
bits 16

;constant
KERNEL_ADDRESS_SEGMENT EQU 0x50
KERNEL_ADDRESS EQU 0

JMP main

%include "include/bootConsole.inc"
%include "include/GDT.inc"
%include "include/A20.inc"
%include "include/NMI.inc"
%include "include/diskIO.inc"

Msg	db	"Preparing to load operating system...",13,10,0
 
;*************************************************;
;	Prints a string
;	DS=>SI: 0 terminated string
;************************************************;
 
Print:
			lodsb		; load next byte from string from SI to AL
			or	al, al	; Does AL=0?
			jz	PrintDone	; Yep, null terminator found-bail out
			CALL printNum
			jmp	Print	; Repeat until null terminator found
PrintDone:
			ret		; we are done, so return
 
;*************************************************;
;	Second Stage Loader Entry Point
;************************************************;
 
main:
	CALL checkA20
	CALL printReg
	MOV AL,0x20
	CALL printNum
	CALL prepeareA20
	CALL checkA20
	CALL printReg
	cli		; clear interrupts
	mov	si, Msg
	MOV AX,SI
	call	Print
	cli		; clear interrupts to prevent triple faults
	XOR DL,DL
	CALL resetFloppy
	MOV AX,KERNEL_ADDRESS_SEGMENT
	MOV BX,KERNEL_ADDRESS
	MOV ES,AX
	MOV CL,4
	XOR CH,CH
	MOV AL,10;10 sector to read
	XOR DX,DX
	CALL readFloppy
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
	MOV EAX,CR0
	OR EAX,1
	MOV CR0,EAX
	JMP 8:stage3

bits 32

stage3:
	MOV AX,0x10
	MOV DS,AX
	MOV ESP,0X90000;need to check the value.why it is this number
	MOV SS,AX
	MOV ES,AX
	CALL KERNEL_ADDRESS_SEGMENT*0x10
	CLI
	HLT
