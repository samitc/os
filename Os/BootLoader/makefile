
all: makeFloppy

makeFloppy: bootStage

bootStage: boot.bin boot2.bin

boot.bin: boot.asm include/*
	$(AsmCompiler) $(ASM_arg) $< -o $@
	dd if=$@ count=1 bs=512 of=$(diskFile) conv=notrunc

boot2.bin: boot2.asm include/*
	$(AsmCompiler) $(ASM_arg) $< -o $@
	dd if=$@ seek=1 count=2 bs=512 of=$(diskFile) conv=notrunc

clean:
	rm -f *.bin
