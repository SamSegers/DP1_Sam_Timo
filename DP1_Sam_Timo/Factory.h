#ifndef _FACTORY_H
#define _FACTORY_H

#include "Component.h"
#include "Defines.h"
#include <stdint.h>

static class Factory
{
protected:
	//std::vector <Component> Types;
public:
	static Component *RequestComponent(uint _type);
	static void ReleaseComponent(Component *_component);
};

#endif