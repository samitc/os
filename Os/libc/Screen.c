#include "../include/CrossCompiler.h"
#include "Screen.h"
#include "AsmIO.h"
void clearScreen()
{
	unsigned int *p=(unsigned int*)(SCREEN_MEM);
	unsigned int v=0x7<<24|0x7<<8;
	while(p<(unsigned int*)SCREEN_END)
	{
		*p=v;
		++p;
	}
	resetCurser(0,0);
}
void putChar(char c,unsigned char att/*=0x3*/)
{
	unsigned char* loc=(unsigned char*)(SCREEN_MEM+(yPos*COLS+xPos)*2);
	*loc=c;
        *(loc+1)=att;
	resetCurser((xPos+1)%COLS,(yPos+xPos/COLS)%ROWS);
}
void putAt(unsigned char x,unsigned char y,char c,unsigned char att/*=0x3*/)
{
	unsigned char* loc=(unsigned char*)(SCREEN_MEM+(y*COLS+x)*2);
	*loc=c;
	*(loc+1)=att;
}
void resetCurser(unsigned char x,unsigned char y)
{
	xPos=x;
	yPos=y;
	unsigned short finalAdr = y * COLS + x;
	out(0x03D4,0x0F);
	out(0x03D5,(unsigned char)(finalAdr&0xFF));
	out(0x03D4,0x0E);
	out(0x03D5,(unsigned char)((finalAdr&0xFF00)>>4));
}
