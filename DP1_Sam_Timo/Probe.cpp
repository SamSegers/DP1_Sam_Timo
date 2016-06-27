#include "Probe.h"

Component* Probe::Clone()
{
	return new Probe();
}
// visit de visitor omdat probe net iets anders doet als de rest.
void Probe::DoThis()
{
	this->pVisitor->Visit(this);
}