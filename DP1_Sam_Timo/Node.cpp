#include "Node.h"

Node::Node(){}
Node::~Node(){}

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