#ifndef _AND_H
#define _AND_H

#include "Node.h"

// voert de AND functionaliteit uit
class AND : public Node
{
public:
	int ExecuteOperation();
	virtual Component* Clone();
	operator const char*() const override { return "AND"; };
};

#endif _AND_H