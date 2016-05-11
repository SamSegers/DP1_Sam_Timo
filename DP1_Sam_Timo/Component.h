#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "Output.h"
#include <mutex>
#include <thread>

class Component
{
protected:
	int _value1;
	int _value2;

	Output *pView;
	std::mutex *pthread;
public:
	Component();
	~Component();

	virtual void CallNext() = 0;
};

#endif