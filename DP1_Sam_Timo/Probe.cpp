#include "Probe.h"

Component* Probe::Clone()
{
	return new Probe();
}

void Probe::DoThis()
{
	this->pVisitor->Visit(this);
}