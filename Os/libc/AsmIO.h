#ifndef _ASMIO_H_
#define _ASMIO_H_
inline void out(unsigned short port,unsigned char val) __attribute__((always_inline));
inline void in(unsigned short port,unsigned char *val) __attribute__((always_inline));
#include "AsmIO.c"
#endif
