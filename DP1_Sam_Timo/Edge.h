#ifndef _EDGE_H
#define _EDGE_H

#include "Component.h"
#include "Node.h"


class Edge : public Component
{
private:
	// in de super classe component zit een std::vector components hoeft dus geen array te maken
	//Node* pNodes[2];
public:


	virtual Component* Clone();
};

#endif