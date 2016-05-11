#include "Circuit.h"
#include <exception>

Circuit::Circuit()
{
	pOutput = new Output();
}

Circuit::~Circuit()
{
	for (int i = 0; i < this->Components.size(); i++)
	{
		Component *pComponent = Components.at(i);

		if (pComponent != nullptr)
		{
			delete pComponent;
			Components.at(i) = nullptr;
			pComponent = nullptr;
		}
	}

	Components.clear();

	if (pOutput != nullptr)
	{
		delete pOutput;
		pOutput = nullptr;
	}
}

int Circuit::CreateEdges()
{
	try
	{
	
	}
	catch (int e)
	{
		return ErrorFound();
	}
	return 1;
}

int Circuit::CreateNodes()
{
	try
	{

	}
	catch (int e)
	{
		return ErrorFound();
	}

	return 1;
}

int Circuit::LinkAll()
{
	try
	{

	}
	catch (int e)
	{
		return ErrorFound();
	}
	return 1;
}

int Circuit::ErrorFound()
{

	return 0;
}

void Circuit::Start()
{

}