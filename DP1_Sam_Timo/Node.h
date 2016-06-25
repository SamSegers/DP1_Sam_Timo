#ifndef _NODE_H
#define _NODE_H

#include "Component.h"
#include "Edge.h"
#include <chrono>
class Node : public Component 
{
public:
	virtual int ExecuteOperation();
	virtual void CallNext();
	virtual Component* Clone();
};

#endif _NODE_H