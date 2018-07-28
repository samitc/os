[BITS 16]      ; 16 bit code generation
[ORG 0x7C00]   ; Origin location

jmp 0x0000:main
%include "include/bootConsole.inc"
%include "include/diskIO.inc"

;constant
STAGE_2_ADDRESS_SEGMENT EQU 0x9FBF
STAGE_2_ADDRESS EQU 0xf
STACK_SEGMENT_START EQU 0X7C0
STACK_POINTER_START EQU 510;size of the boot loader(shold not reach the start of the loader when we run stage 1 and after loading stage 2 we can ovveride the boot loader

main:
	XOR AX,AX
	MOV CX,STACK_SEGMENT_START
	MOV BX,STACK_POINTER_START
	MOV DS,AX
	;init stuck segments
	MOV SP,BX
	MOV SS,CX
	
	CLI
	INT 0x12;get memory
	;CALL printReg
	MOV AL,0x20
	;CALL printNum
	MOV AX,0xe801
	INT 0x15;get memory
	;CALL printReg
	MOV AL,0xA
	;CALL printNum
	;reset floppy to read from the first sector
	;remember that in init time from the bios dl contain the drive number
	XOR DL,DL
	CALL resetFloppy
	MOV AX,STAGE_2_ADDRESS_SEGMENT;set the location of the new read sector(in ES:BX)
	MOV ES,AX
	MOV BX,STAGE_2_ADDRESS
	MOV CH,0;track number
	MOV AL,2;number of sectors
	MOV CL,2;sector number
	XOR DX,DX;head number
	CALL readFloppy
	;jump to the next boot level
	JMP STAGE_2_ADDRESS_SEGMENT:STAGE_2_ADDRESS
	;PUSH WORD STAGE_2_ADDRESS_SEGMENT
	;PUSH WORD STAGE_2_ADDRESS
	;RETF

	; End Matter
	times 510-($-$$) db 0	; Fill the rest with zeros
	stack_start:
	dw 0xAA55		; Boot loader signature
