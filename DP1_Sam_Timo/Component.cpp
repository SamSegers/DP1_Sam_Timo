#include "Component.h"

Component::Component()
{
	this->_value1 = -1;
	this->_value2 = -1;

	this->thread = std::thread(&Component::WaitForValues,this);
}

Component::Component(std::string _id)
{
	this->_value1 = -1;
	this->_value2 = -1;

	this->_id = _id;

	this->thread = std::thread(&Component::WaitForValues, this);
}

Component::~Component()
{
	// voor het geval dat
	if (this->thread.joinable())
		this->thread.join();
}

void Component::WaitForValues()
{
	mutex.lock();
	
	mutex.unlock();
}

void Component::SetNext(std::vector<Component *> Next)
{
	for (int i = 0; i < Next.size(); i++)
		this->pComponents.push_back(Next.at(i));
}

void Component::SetValues(int value1,int value2)
{
	this->_value1 = value1;
	this->_value2 = value2;
}

void Component::CallNext()
{
	// join de threads
	thread.join();
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