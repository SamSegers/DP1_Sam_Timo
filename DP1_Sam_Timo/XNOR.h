#ifndef _XNOR_H
#define _XNOR_H

#include "Node.h"

class XNOR : public Node
{
public:
	int ExecuteOperation();
	virtual Component* Clone();
};

#endif _XNOR_H