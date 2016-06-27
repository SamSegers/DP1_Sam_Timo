#include "Component.h"

Component::Component()
{

}
Component::~Component()
{
	
}


void Component::InsertValue(int value)
{
	this->values.push_back(value);
}



Component* Component::Clone()
{
	return new Component();
}

std::vector<int> Component::GetValues()
{
	return this->values;
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