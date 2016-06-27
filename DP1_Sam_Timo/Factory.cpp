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

	// clone een nieuwe object
	return Factory::Types.at(_type)->Clone();

	//return &this->Types.at(_type);
}

// delete een item dat we binnen krijgen.
void Factory::ReleaseComponent(Component *_component)
{
	if (_component != nullptr)
	{
		delete _component;
		_component = nullptr;
	}
}

// voeg nieuwe items toe zodat we die kunnen clonen
void Factory::AddComponent(Component *_component)
{
	Factory::Types.push_back(_component);
}

// roept de instantie aan.
Factory * Factory::instance()
{
	if (!pFactory)
	{
		pFactory = new Factory();
	}
	return pFactory;
}