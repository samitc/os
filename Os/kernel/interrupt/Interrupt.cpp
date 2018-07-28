#include "Interrupt.h"
#include <utility>
#include "BaseInterrupt.h"
Interrupt::Interrupt(void ** memLoc):interrupts((BaseInterrupt**)*memLoc)
{
	*memLoc=((char*)(*memLoc))+MAX_INTERRUPT*(sizeof(BaseInterrupt*));
	for(int i=0;i<MAX_INTERRUPT;i++)
	{
		interrupts[i]=nullptr;
	}
}
int Interrupt::addInterrupt(BaseInterrupt &&interrupt)
{
	int i=0;
	while(i<MAX_INTERRUPT&&interrupts[i]!=nullptr)
	{
		++i;
	}
	if(i<MAX_INTERRUPT)
	{
		*interrupts[i]=std::move(interrupt);
	}
	return i;
}
void Interrupt::operator()()
{
	int i=0;
	while(i<MAX_INTERRUPT&&interrupts[i]!=nullptr)
	{
		(*interrupts[i])();
	}
}
