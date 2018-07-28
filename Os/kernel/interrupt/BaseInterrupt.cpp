#include "BaseInterrupt.h"
void BaseInterrupt::operator()()
{
}
bool BaseInterrupt::needToCallWhenIdle() const
{
	return false;
}
