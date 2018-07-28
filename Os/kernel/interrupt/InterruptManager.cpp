#include "InterruptManager.h"
#include "Interrupt.h"
std::map<unsigned char,Interrupt> *interruptes;
void InterruptManager::setInterrupt(unsigned char interruptNumber,Interrupt && interrupt)
{
	auto newLoc=interrupts.find(interruptNumber);
	interrupts.insert(newLoc,std::pair<unsigned char,Interrupt&&>(interruptNumber,std::move(interrupt)));
}
void InterruptManager::updateInterrupt()
{
	intRegLoc.base=*((unsigned int*)(&intDesc[0]));
	intRegLoc.limit=(unsigned short)(sizeof(intDescriptor)*NUM_OF_INTERRUPT);
	interruptes=&interrupts;	
}
template<int INT_N> void interruptHandler()
{
	auto inter=interruptes->find(INT_N);
	((*inter).second)();
}
template<> void interruptHandler<255>()
{
}
