#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_
constexpr int MAX_INTERRUPT=10;
class BaseInterrupt;
class Interrupt
{
public:
	Interrupt()=delete;
	Interrupt(void **);
	~Interrupt();
	int addInterrupt(BaseInterrupt &&);
	void operator()();
private:
	BaseInterrupt **interrupts;
};
#endif
