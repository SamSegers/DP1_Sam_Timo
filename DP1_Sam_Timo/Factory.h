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

// maakt alle components aan
class Factory
{
protected:
	static std::vector <Component *> Types;
	//singleton
	static Factory *pFactory;
public:
	Factory();
	~Factory();
	static Factory *instance();
	Component *RequestComponent(uint _type);
	void ReleaseComponent(Component *_component);
	void AddComponent(Component *_component);
};

#endif