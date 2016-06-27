#include "Node.h"

int Node::ExecuteOperation()
{
	return 1;
}
// gaat door naar de visitor die de execute aanroept
void Node::DoThis()
{
	pVisitor->Visit(this);
	//if(this->ExecuteOperation())
		//Component::DoThis();
}
// clone dit
Component* Node::Clone()
{
	return new Node();
}
// haal de eerste waarde op
int Node::GetValue() 
{
	return values.size() > 0 ? values[0] : 0;
}