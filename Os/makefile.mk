AsmCompiler=nasm
CCompiler=gcc
CppCompiler=g++
LdCompiler=ld

#variables
debug_compile=1

#condition variables
ifdef debug_compile
CPP_debug=-g
CC_debug=-g
ASM_debug=-g
endif

#global compile argument
ASM_arg= $(ASM_debug)
CC_arg=-m32 -std=c11 $(CC_debug)
CPP_arg=-m32 -std=c++11 $(CPP_debug)
LD_arg=-melf_i386

export
