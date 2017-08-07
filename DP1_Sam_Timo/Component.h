#ifndef _COMPONENT_H
#define _COMPONENT_H


#include "Visitor.h"
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

// Object dat de waardes bevat. probes/nodes/inputs overerven uiteindelijk van dit.
class Component
{
protected:
	std::vector<int> values;
	
	std::string _id;

	std::shared_ptr<Visitor> pVisitor;
public:
	Component();
	~Component();

	std::vector<int> GetValues();
	
	virtual void InsertValue(int value);

	

	virtual Component* Clone();

	

	void Accept(std::shared_ptr<Visitor> pVisitor);

	void SetId(std::string _id);
	std::string GetId();
};

#endif