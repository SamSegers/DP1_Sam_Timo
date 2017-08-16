#ifndef _PROBE_H
#define _PROBE_H

#include "Composite\Composite.h"

// hier komen de uiteindelijke waardes
class Probe : public Composite
{
protected:
	
public:
	virtual void Accept(std::shared_ptr<Visitor> pVisitor);
	const static char* NAME;

	virtual Component* Clone();
	operator const char*() const override { return "Probe"; };
};

#endif