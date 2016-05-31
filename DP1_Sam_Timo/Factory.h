#ifndef _FACTORY_H
#define _FACTORY_H

#include "Component.h"
#include "Defines.h"
#include "Node.h"
#include "AND.h"
#include "NAND.h"
#include "NOR.h"
#include "NOT.h"
#include "OR.h"
#include "XNOR.h"
#include "XOR.h"
#include "Input.h"
#include "Probe.h"
#include <stdint.h>

class Factory
{
protected:
	//std::vector <Component> Types;
	static Factory *pFactory;
public:
	static Factory *instance();
	Component *RequestComponent(uint _type);
	void ReleaseComponent(Component *_component);
};

#endif