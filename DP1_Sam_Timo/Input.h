#ifndef _INPUT_H
#define _INPUT_H

#include "Component.h"

class Input : public Component
{
public:
	virtual Component* Clone();
};

#endif