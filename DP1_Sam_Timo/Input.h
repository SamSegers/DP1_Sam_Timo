#ifndef _INPUT_H
#define _INPUT_H

#include "Composite.h"

// bij start krijgt deze een waarde en geeft hem door.
// doet niet veel maar zit er in voor de voledigheid
class Input : public Composite
{
public:
	virtual Component* Clone();
};

#endif