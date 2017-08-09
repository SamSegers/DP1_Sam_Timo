#ifndef _OR_H
#define _OR_H

#include "Node.h"

// voert de OR functionaliteit uit
class OR : public Node
{
public:
	int ExecuteOperation();
	virtual Component* Clone();
	operator const char*() const override { return "OR"; };
};

#endif _OR_H
