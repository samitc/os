C_arg=-ffreestanding
all: makeFloppy

makeFloppy: kernelB

kernelB: Screen.o #AsmIO.o

Screen.o: Screen.c
	$(CCompiler) $(C_arg) $(CC_arg) -c $< -o ../kernel/$@
AsmIO.o: AsmIO.c
	$(CCompiler) $(C_arg) $(CC_arg) -c $< -o ../kernel/$@

clean:
	rm -f *.o
	rm -f *.bin
