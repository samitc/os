#ifndef _SCREEN_H_
#define _SCREEN_H_
#define SCREEN_MEM	0xB8000
#define COLS	(unsigned char)80
#define ROWS	(unsigned char)25
#define SCREEN_END	SCREEN_MEM+(ROWS*COLS)*2
static unsigned char xPos=0;
static unsigned char yPos=0;
void clearScreen();
void putChar(char c,unsigned char att/*=0x3*/);
void putAt(unsigned char x,unsigned char y,char c,unsigned char att/*=0x3*/);
void resetCurser(unsigned char x,unsigned char y);
#endif
