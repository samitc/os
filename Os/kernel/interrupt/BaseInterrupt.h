#ifndef _BASEINTERRUPT_H_
#define _BASEINTERRUPT_H_

class BaseInterrupt
{
public:
	BaseInterrupt()=default;
	BaseInterrupt(const BaseInterrupt&)=delete;
	BaseInterrupt(BaseInterrupt&&)=default;
	BaseInterrupt& operator=(BaseInterrupt&&)=default;
	virtual ~BaseInterrupt()=default;
	virtual void operator()();
	virtual bool needToCallWhenIdle() const;
	virtual void idleHandle() = 0;
private:
};
#endif
