#ifndef _PROBE_H
#define _PROBE_H

#include "Component.h"

class Probe : public Component
{
protected:
	
public:
	virtual void CallNext();

	virtual Component* Clone();
};

#endif