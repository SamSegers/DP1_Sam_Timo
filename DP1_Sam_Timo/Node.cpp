#include "Node.h"

int Node::ExecuteOperation()
{
	return 1;
}

void Node::DoThis()
{
	pVisitor->Visit(this);
	//if(this->ExecuteOperation())
		//Component::DoThis();
}

Component* Node::Clone()
{
	return new Node();
}

int Node::GetValue() 
{
	return values.size() > 0 ? values[0] : 0;
}