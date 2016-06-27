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
	
	std::string _id;

	Visitor *pVisitor;
public:
	Component();
	~Component();

	std::vector<int> GetValues();
	
	virtual void InsertValue(int value);

	

	virtual Component* Clone();

	

	void Accept(Visitor *pVisitor);

	void SetId(std::string _id);
	std::string GetId();
};

#endif