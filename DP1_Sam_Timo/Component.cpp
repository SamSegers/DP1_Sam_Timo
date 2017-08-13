#include "Component.h"

Component::Component()
{

}
Component::~Component()
{
	
}
// voeg waarde toe aan de vector
void Component::InsertValue(int value)
{
	this->values.push_back(value);
}
// clone een nieuwe component
Component* Component::Clone()
{
	return new Component();
}
// haal waardes op.
std::vector<int> Component::GetValues()
{
	return this->values;
}
// zet de visitor
void Component::Accept(std::shared_ptr<Visitor> pVisitor)
{
	
}

void Component::SetId(std::string _id)
{
	this->_id = _id;
}

std::string Component::GetId()
{
	return this->_id;
}