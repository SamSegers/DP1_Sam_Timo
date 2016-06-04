#ifndef _NOR_H
#define _NOR_H

#include "Node.h"

class NOR : public Node
{
public:
	int ExecuteOperation();
	virtual Component* Clone();
};

#endif _NOR_H