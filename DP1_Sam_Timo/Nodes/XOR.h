#ifndef _XOR_H
#define _XOR_H

#include "Node.h"

// voert de XOR functionaliteit uit
class XOR : public Node
{
public:
	int ExecuteOperation();
	virtual Component* Clone();
	operator const char*() const override { return "XOR"; };
};

#endif _XOR_H