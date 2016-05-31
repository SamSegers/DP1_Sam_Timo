#include "Factory.h"

Component *Factory::RequestComponent(uint _type)
{
	if (_type == _NODE)
		return new Node();
	else if (_type == _EDGE)
		return new Edge();
	else if (_type == _INPUT)
		return new Input();
	else if (_type == _PROBE)
		return new Probe();
	else if (_type == _AND)
		return new AND();
	else if (_type == _NAND)
		return new NAND();
	else if (_type == _NOR)
		return new NOR();
	else if (_type == _NOT)
		return new NOT();
	else if (_type == _OR)
		return new OR();
	else if (_type == _XNOR)
		return new XNOR();
	else if (_type == _XOR)
		return new XOR();
	return nullptr;
	//return &this->Types.at(_type);
}

void Factory::ReleaseComponent(Component *_component)
{
	if (_component != nullptr)
	{
		delete _component;
		_component = nullptr;
	}
}

Factory * Factory::instance()
{
	if (!pFactory)
		pFactory = new Factory();
	return pFactory;
}