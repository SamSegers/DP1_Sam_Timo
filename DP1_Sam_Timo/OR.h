#ifndef _OR_H
#define _OR_H

#include "Node.h"

class OR : public Node
{
public:
	int ExecuteOperation();
	virtual Component* Clone();
};

#endif _OR_H
