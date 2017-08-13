#ifndef _NOR_H
#define _NOR_H

#include "Node.h"
// voert de NOR functionaliteit uit
class NOR : public Node
{
public:
	int ExecuteOperation();
	virtual Component* Clone();
	operator const char*() const override { return "NOR"; };
};

#endif _NOR_H