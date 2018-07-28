#ifndef _INTERRUPTMANAGER_H_
#define _INTERRUPTMANAGER_H_
#include <map>
#include "../../include/CrossCompiler.h"
class Interrupt;
class InterruptManager
{
public:
	InterruptManager()=default;
	InterruptManager(const InterruptManager&)=delete;
	void setInterrupt(unsigned char,Interrupt&&);
	void updateInterrupt();
private:
	struct intDescriptor
{
        unsigned short limit;
        unsigned short baseLow;
        unsigned char baseMiddle;
        unsigned short flags;
        unsigned char baseHi;
} PACKED;
struct intPtr
{
        unsigned short limit;
        unsigned int base;
} PACKED;
	static intDescriptor createDesc(const Interrupt&);
	constexpr static int NUM_OF_INTERRUPT=255;
	std::map<unsigned char,Interrupt> interrupts;
	intPtr intRegLoc;
	intDescriptor intDesc[NUM_OF_INTERRUPT];
};
#endif
