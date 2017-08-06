#pragma once
#include "Node.h"

class Mediator
{
protected:
	std::vector<Node*> _nodes;
	static Mediator *pMediator;

public:
	Mediator();
	~Mediator();
	static Mediator *instance();
	void PassValue(Node *pSource, Node* pTarget);
};