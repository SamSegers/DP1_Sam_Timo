#include "Factory.h"

Factory *Factory::pFactory = nullptr;
std::vector<Component *> Factory::Types;

Factory::Factory()
{

}

Factory::~Factory()
{
	for (int i = 0; i < Factory::Types.size(); i++)
		Factory::ReleaseComponent(Factory::Types.at(i));

	Factory::Types.clear();
}

Component *Factory::RequestComponent(uint _type)
{
	/*if (_type == _NODE)
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
	return nullptr;*/

	return Factory::Types.at(_type)->Clone();

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
	{
		Factory::Types.push_back(new Node());
		Factory::Types.push_back(new Edge());
		Factory::Types.push_back(new Input());
		Factory::Types.push_back(new Probe());
		Factory::Types.push_back(new AND());
		Factory::Types.push_back(new NAND());
		Factory::Types.push_back(new NOR());
		Factory::Types.push_back(new NOT());
		Factory::Types.push_back(new OR());
		Factory::Types.push_back(new XNOR());
		Factory::Types.push_back(new XOR());
		pFactory = new Factory();
	}
	return pFactory;
}