#ifndef _NODE_H
#define _NODE_H

#include "Component.h"
#include "Edge.h"
#include <chrono>
class Node : public Component 
{
protected:
	// er zit een std::vector in component hoeft geen array te maken
	//Edge* pEdges[2];
public:

	virtual int ExecuteOperation();
	virtual void CallNext();
	virtual Component* Clone();
};

#endif _NODE_H