#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "Output.h"
#include <mutex>
#include <thread>
#include <vector>

extern std::mutex _mutex;

class Component
{
protected:
	std::vector<int> values;
	std::vector<Component *> pComponents;
	Output *pView;
	std::string _id;
public:
	Component();
	~Component();

	std::vector<Component*> GetNext();
	virtual void AddNext(Component *Next);
	virtual void InsertValue(int value);

	virtual void CallNext();

	virtual Component* Clone();

	void SetId(std::string _id);
	std::string GetId();
};

#endif