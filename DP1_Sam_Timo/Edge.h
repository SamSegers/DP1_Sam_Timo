#ifndef _EDGE_H
#define _EDGE_H

#include "Composite.h"
#include "Node.h"

// edge doet niet veel behalve naar de volgende roepen. zit er meer in voor de voledigheid
class Edge : public Composite
{
private:
	// in de super classe component zit een std::vector components hoeft dus geen array te maken
	//Node* pNodes[2];
public:


	virtual Component* Clone();
};

#endif