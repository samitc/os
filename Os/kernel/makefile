
all: makeFloppy

makeFloppy: kernelB

kernelB: kmain.o
	$(LdCompiler) -o kernel.o -Ttext 0x500 $(LD_arg) $^ Screen.o
	objcopy -O binary kernel.o kernel.bin
	dd if=kernel.bin seek=3 count=10 bs=512 of=$(diskFile) conv=notrunc

kmain.o: kmain.c
	$(CCompiler) -ffreestanding $(CC_arg) -c $< -o $@
clean:
	rm -f *.o
	rm -f *.bin
