#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "Output.h"
#include <mutex>
#include <thread>
#include <vector>

class Component
{
protected:
	int _value1;
	int _value2;
	std::vector<Component *> pComponents;
	Output *pView;
	std::mutex mutex;
	std::thread thread;

	void WaitForValues();

public:
	Component();
	~Component();

	virtual void SetValues(int value1 = -1,int value2 = -1);
	virtual void CallNext();
};

#endif