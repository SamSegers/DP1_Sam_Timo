#ifndef _XOR_H
#define _XOR_H

#include "Node.h"

class XOR : public Node
{
public:
	void ExecuteOperation();
	virtual Component* Clone();
};

#endif _XOR_H