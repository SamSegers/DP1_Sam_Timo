#ifndef _NODE_H
#define _NODE_H

#include "Composite.h"
#include "Edge.h"
#include <chrono>

class Node : public Composite 
{
public:
	virtual int ExecuteOperation();
	virtual void DoThis();
	virtual Component* Clone();
	int GetValue();
};

#endif _NODE_H