%IFNDEF _A20_INC_
%DEFINE _A20_INC_
%include "include/KeyBoardIO.inc"
%include "include/bootConsole.inc"
prepeareA20:
	CLI
	call checkA20
	TEST AX,0xFFFF
	JNZ A20_ready
	CALL enableA20Bios
	CALL checkA20
	TEST AX,0xFFFF
	JNZ A20_ready
	CALL enableA20KeyBoard
	CALL checkA20
	TEST AX,0xFFFF
	JNZ A20_ready
	CALL fastA20
	MOV CX,1000
	fastA20Test:
	CALL checkA20
	JNZ A20_ready
	LOOP fastA20Test
	A20_faild:
	MOV AX,0
	JMP A20_end
	A20_ready:
	MOV AX,1
	A20_end:
	STI
ret
REGULAR_SEGMENT EQU 0
LOOP_SEGMENT EQU 0xFFFF
REGULAR_ADDRESS EQU 0x7DFE
LOOP_ADDRESS EQU 0x7E0E
checkA20:;return in ax 0 if disable 1 if enable
PUSH DS
PUSH ES
	MOV BX,REGULAR_SEGMENT
	XOR AX,AX
	MOV DS,BX
	MOV BYTE [DS:REGULAR_ADDRESS],0x00
	MOV BX,LOOP_SEGMENT
	MOV ES,BX
	MOV BYTE [ES:LOOP_ADDRESS],0xFF
	TEST BYTE [DS:REGULAR_ADDRESS],0xFF
	JNZ not_equle
	INC AX
	not_equle:
POP ES
POP DS
ret
enableA20Bios:;if error cf will set,error code in ah.ah==0x86 function not support
	MOV AX,0x2401
	INT 0x15
ret
enableA20KeyBoard:
	CALL wait_write_ready
	MOV AL,0xAD
	CALL keyBoard_status_write
	CALL wait_write_ready
        MOV AL,0xD0
        CALL keyBoard_status_write
	CALL wait_read_ready
        CALL keyBoard_buffer_read
	MOV BL,AL
	CALL wait_write_ready
	MOV AL,0xD1
	CALL keyBoard_status_write
	CALL wait_write_ready
	MOV AL,BL
	OR AL,2
	CALL keyBoard_buffer_write
	CALL wait_write_ready
	MOV AL,0xAE
	CALL keyBoard_status_write
	CALL wait_write_ready
ret
fastA20:
	IN AX,0x92
	OR AL,2
	OUT 0x92,AL
RET
%ENDIF
