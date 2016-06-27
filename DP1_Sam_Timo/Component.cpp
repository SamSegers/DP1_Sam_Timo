#include "Component.h"

Component::Component()
{

}
Component::~Component()
{
	this->pComponents.clear();
	this->PreviousComponents.clear();
}

void Component::AddNext(Component *Next)
{
	this->pComponents.push_back(Next);
}

std::vector<Component*> Component::GetNext() 
{
	return pComponents;
}

std::vector<Component*> Component::GetPrevious()
{
	return PreviousComponents;
}

void Component::InsertValue(int value)
{
	this->values.push_back(value);
}

void Component::CallNext()
{
	if (this->pComponents.size() == 0)
	{
		return;
	}

	this->pVisitor->Visit(this);
}

Component* Component::Clone()
{
	return new Component();
}

std::vector<int> Component::GetValues()
{
	return this->values;
}

void Component::SetPreviousComponent(Component* Previous)
{
	this->PreviousComponents.push_back(Previous);
}

int Component::CountPreviousComponents()
{
	return this->PreviousComponents.size();
}

void Component::Accept(Visitor *pVisitor)
{
	this->pVisitor = pVisitor;
}

void Component::SetId(std::string _id)
{
	this->_id = _id;
}

std::string Component::GetId()
{
	return this->_id;
}