#include "Factory.h"

Component *Factory::RequestComponent(uint _type)
{
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