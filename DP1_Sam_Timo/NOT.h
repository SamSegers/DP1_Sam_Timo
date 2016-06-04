#ifndef _NOT_H
#define _NOT_H

#include "Node.h"

class NOT : public Node
{
public:
	int ExecuteOperation();
	virtual Component* Clone();
};

#endif _NOT_H