#include "Node.h"

int Node::ExecuteOperation()
{
	return 1;
}
// gaat door naar de visitor die de execute aanroept
void Node::Accept(std::shared_ptr<Visitor> pVisitor)
{
	if (this->pComponents.size() == 0)
		return;

	pVisitor->Visit(this);
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