#ifndef _PROBE_H
#define _PROBE_H

#include "Composite.h"

// hier komen de uiteindelijke waardes
class Probe : public Composite
{
protected:
	
public:
	virtual void Accept(std::shared_ptr<Visitor> pVisitor);

	virtual Component* Clone();
};

#endif