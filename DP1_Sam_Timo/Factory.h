#ifndef _FACTORY_H
#define _FACTORY_H

#include "Composite\Component.h"
#include "Defines.h"
#include "Nodes\Node.h"
#include "Nodes\AND.h"
#include "Nodes\NAND.h"
#include "Nodes\NOR.h"
#include "Nodes\NOT.h"
#include "Nodes\OR.h"
#include "Nodes\XNOR.h"
#include "Nodes\XOR.h"
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