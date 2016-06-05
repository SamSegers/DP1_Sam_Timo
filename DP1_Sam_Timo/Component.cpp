#include "Component.h"

Component::Component()
{

}
Component::~Component()
{
}

void Component::AddNext(Component *Next)
{
	this->pComponents.push_back(Next);
}

std::vector<Component*> Component::GetNext() 
{
	return pComponents;
}

void Component::InsertValue(int value)
{
	this->values.push_back(value);
}

void Component::CallNext()
{
	if (this->pComponents.size() == 0)
	{
		this->pView->Print("Error in circuit!");
		return;
	}

	for (int i = 0; i < this->pComponents.size(); i++)
	{
		_mutex.lock();
		if (this->_id != "")
			this->pView->Print("id:" + this->_id);
		_mutex.unlock();
		this->pComponents.at(i)->InsertValue(this->values.at(0));
		std::thread t(&Component::CallNext,this->pComponents.at(i));
		t.detach();
		//this->pComponents.at(i)->CallNext();
	}
}

Component* Component::Clone()
{
	return new Component();
}

void Component::SetId(std::string _id)
{
	this->_id = _id;
}

std::string Component::GetId()
{
	return this->_id;
}