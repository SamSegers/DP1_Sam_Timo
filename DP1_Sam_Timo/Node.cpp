#include "Node.h"

Node::Node()
{
	Component::Component();
}

Node::~Node()
{
	Component::~Component(); 
}

void Node::CallNext() {
	for (int i = 0; i < pComponents.size(); i++)
	{
		if (pComponents.at(i) != nullptr)
		{
			// roep volgende aan
		}
	}
}

void Node::ExecuteOperation()
{

}

void Node::WaitForValues() {

}

Component* Node::Clone()
{
	return new Node();
}
