#include "../libc/Screen.h"
void main()
{
	char *videoMem=(char*)0xB8000;
	*videoMem='X';
	clearScreen();
	char * loading="start loading your operation system...";
	resetCurser(20,5);
	char *p=loading;
	while(*p)
	{
		putChar(*p,0x3);
		p++;
	}
	while(1)
	{
	}
}
