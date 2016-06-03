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
	std::string _id;

	void WaitForValues();

public:
	Component();
	Component(std::string _id);
	~Component();

	virtual void SetNext(std::vector<Component *>);
	virtual void SetValues(int value1 = -1,int value2 = -1);

	virtual void CallNext();

	virtual Component* Clone();

	void SetId(std::string _id);
	std::string GetId();
};

#endif