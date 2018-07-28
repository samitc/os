#include "AsmIO.h"
#include "../include/CrossCompiler.h"
inline void out(unsigned short port,unsigned char val)
{
	ASM("out %0, %1" :: "a" (val), "dN" (port));
//	ASM("out %eax,%ebx");
//	ASM("out %0, %1" : : "a" (0xfe), "g" (vvv));
//	ASM("outl %1,%0"::"r"(ad),"r"(va));
}
inline void in(unsigned short port,unsigned char *val)
{
	ASM("in %1, %0" :"=r" (*val): "dN" (port));
}
