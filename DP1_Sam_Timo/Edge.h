#ifndef _EDGE_H
#define _EDGE_H

#include "Composite.h"
#include "Node.h"

// edge doet niet veel behalve naar de volgende roepen. zit er meer in voor de voledigheid
class Edge : public Composite
{
public:
	virtual Component* Clone();
	operator const char*() const override { return "Edge"; };
};

#endif