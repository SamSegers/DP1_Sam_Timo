#ifndef _MEDIATOR_H
#define _MEDIATOR_H
#include "Nodes\Node.h"

class Mediator
{
protected:
	static Mediator *pMediator;
public:
	Mediator();
	~Mediator();
	static Mediator *instance();
	void PassValue(Composite *pSource, Composite* pTarget);
};

#endif