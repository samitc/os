lowMemory:;return in ax the amount of memory below the 1 mb
	XOR AX,AX
	INT 0x12
	JC error
	TEST AX,AX
	JZ error
	JMP retMem
	error:
	MOV AX,0xFFFF
	retMem:
RET
allMemory:;temp memory will locate at bootloader end.return in AX the total byte and in cx the size of one entry
	PUSH EBX
	PUSH EDX
	PUSH ES
	PUSH DI

	MOV AX,0x7E0
	MOV ES,AX
	XOR DI,DI
	MOV EAX,0xE820
	XOR EBX,EBX
	MOV EDX,0x534D4150
	MOV ECX,24
	INT 0x15
	JMP end_data_loop
	data_loop:
	ADD DI,CX
	MOV CX,24
	MOV EAX,0xE820
	INT 0x15
	end_data_loop:
	JC data_error
	CMP EAX,EDX
	JNZ data_error
        TEST EBX,EBX
        JNZ data_loop
	data_end:
	MOV AX,DI
	JMP mem_end
	data_error:
	MOV AX,555
	CALL printReg

	mem_end:
	POP DI
	POP ES
	POP EDX
	POP EBX
RET
