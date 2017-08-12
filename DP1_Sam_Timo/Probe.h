#ifndef _PROBE_H
#define _PROBE_H

#include "Composite.h"

// hier komen de uiteindelijke waardes
class Probe : public Composite
{
protected:
	
public:
	const static char* NAME;

	virtual void DoThis();

	virtual Component* Clone();
	operator const char*() const override { return "Probe"; };
};

#endif