
all: makeFloppy

makeFloppy: kernelB

kernelB: kmain.o
	$(LdCompiler) -o kernel.bin -Ttext 0x500 $(LD_arg) $^ Screen.o --oformat binary
	dd if=kernel.bin seek=3 count=10 bs=512 of=$(diskFile) conv=notrunc

kmain.o: kmain.c
	$(CCompiler) -ffreestanding $(CC_arg) -c $< -o $@
	objdump -d --disassembler-options=intel $@ > $@.bin
clean:
	rm -f *.o
	rm -f *.bin
