#include "Probe.h"

Component* Probe::Clone()
{
	return new Probe();
}

void Probe::CallNext()
{
	_mutex.lock();
	this->pView->Print("Final output of: " + this->_id + " is: " + std::to_string(this->values.at(0)));
	_mutex.unlock();
}