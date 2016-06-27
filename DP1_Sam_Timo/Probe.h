#ifndef _PROBE_H
#define _PROBE_H

#include "Composite.h"

// hier komen de uiteindelijke waardes
class Probe : public Composite
{
protected:
	
public:
	virtual void DoThis();

	virtual Component* Clone();
};

#endif