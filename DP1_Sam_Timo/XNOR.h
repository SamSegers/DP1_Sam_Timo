#ifndef _XNOR_H
#define _XNOR_H

#include "Node.h"

// voert de XNOR functionaliteit uit
class XNOR : public Node
{
public:
	int ExecuteOperation();
	virtual Component* Clone();
};

#endif _XNOR_H