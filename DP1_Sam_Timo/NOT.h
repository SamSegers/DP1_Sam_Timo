#ifndef _NOT_H
#define _NOT_H

#include "Node.h"

// voert de NOT functionaliteit uit
class NOT : public Node
{
public:
	int ExecuteOperation();
	virtual Component* Clone();
};

#endif _NOT_H