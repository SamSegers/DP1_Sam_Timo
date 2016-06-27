#include "Node.h"


int Node::ExecuteOperation()
{
	return 1;
}

void Node::CallNext()
{
	pVisitor->Visit(this);
	//if(this->ExecuteOperation())
		//Component::CallNext();
}

Component* Node::Clone()
{
	return new Node();
}
