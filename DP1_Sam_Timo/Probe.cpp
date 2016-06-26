#include "Probe.h"

Component* Probe::Clone()
{
	return new Probe();
}

void Probe::CallNext()
{
	this->pView->Print("Final output of: " + this->_id + " is: " + std::to_string(this->values.at(0)));
}