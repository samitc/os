%IFNDEF _BOOT_CONSOLE_INC_
%DEFINE _BOOT_CONSOLE_INC_
printReg:;ax
PUSH CX
PUSH AX
PUSH DX
PUSH BX
        MOV BX,0xA
        XOR CX,CX
        div_loop:
                XOR DX,DX
                DIV BX
                PUSH DX
                INC CX
                TEST AX,0xFFFF
        JNZ div_loop
        print_loop:
                POP AX
                ADD AX,48
                CALL printNum
                loop print_loop

POP BX
POP DX
POP AX
POP CX

ret

printNum:
PUSH AX
PUSH BX
        MOV AH,0x0E
        XOR BX,BX
        INT 0x10
POP BX
POP AX
ret
%ENDIF
