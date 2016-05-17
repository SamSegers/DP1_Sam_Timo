#ifndef _EDGE_H
#define _EDGE_H

#include "Component.h"
#include "Node.h"

class Node;
class Edge : public Component
{
private:
	Node* pNodes[2];
public:
	void CallNext() override;
};

#endif