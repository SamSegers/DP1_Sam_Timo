#include "Component.h"

Component::Component()
{
	this->_value1 = -1;
	this->_value2 = -1;

	this->thread = std::thread(&Component::WaitForValues,this);
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

void Component::SetValues(int value1 = -1,int value2 = -1)
{
	this->_value1 = value1;
	this->_value2 = value2;
}

void Component::CallNext()
{
	// join de threads
	thread.join();
}