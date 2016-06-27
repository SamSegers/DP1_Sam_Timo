#include "Probe.h"

Component* Probe::Clone()
{
	return new Probe();
}

void Probe::CallNext()
{
	this->pVisitor->Visit(this);
}