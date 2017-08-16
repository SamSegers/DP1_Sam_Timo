#ifndef _NODE_H
#define _NODE_H
#include "..\Composite\Composite.h"
#include "..\Composite\Edge.h"
#include <chrono>

// Overerven de functionaliteiten van.
class Node : public Composite 
{
public:
	virtual int ExecuteOperation();
	virtual void Accept(std::shared_ptr<Visitor> pVisitor);
	virtual Component* Clone();
	int GetValue();
	operator const char*() const override { return "Node"; };
};

#endif _NODE_H