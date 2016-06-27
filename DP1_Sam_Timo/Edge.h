#ifndef _EDGE_H
#define _EDGE_H

#include "Composite.h"
#include "Node.h"


class Edge : public Composite
{
private:
	// in de super classe component zit een std::vector components hoeft dus geen array te maken
	//Node* pNodes[2];
public:


	virtual Component* Clone();
};

#endif