#ifndef _COMPONENT_H
#define _COMPONENT_H


#include "Visitor.h"
#include <mutex>
#include <thread>
#include <vector>

class Component
{
protected:
	std::vector<int> values;
	std::vector<Component *> pComponents;
	std::vector<Component *> PreviousComponents;
	std::string _id;

	Visitor *pVisitor;
public:
	Component();
	~Component();

	std::vector<int> GetValues();
	std::vector<Component*> GetNext();
	std::vector<Component*> GetPrevious();
	virtual void AddNext(Component *Next);
	virtual void InsertValue(int value);

	virtual void CallNext();

	virtual Component* Clone();

	void SetPreviousComponent(Component *Previous);
	
	int CountPreviousComponents();

	void Accept(Visitor *pVisitor);

	void SetId(std::string _id);
	std::string GetId();
};

#endif