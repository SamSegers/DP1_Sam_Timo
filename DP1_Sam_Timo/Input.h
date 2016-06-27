#ifndef _INPUT_H
#define _INPUT_H

#include "Composite.h"

class Input : public Composite
{
public:
	virtual Component* Clone();
};

#endif