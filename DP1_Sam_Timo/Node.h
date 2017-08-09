#ifndef _NODE_H
#define _NODE_H

#include "Composite.h"
#include "Edge.h"
#include <chrono>

// Overerven de functionaliteiten van.
class Node : public Composite 
{
public:
	virtual int ExecuteOperation();
	virtual void DoThis();
	virtual Component* Clone();
	int GetValue();
	operator const char*() const override { return "Node"; };
};

#endif _NODE_H