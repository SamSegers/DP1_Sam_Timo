#include "Composite.h"

Composite::~Composite()
{
	this->pComponents.clear();
	this->PreviousComponents.clear();
}

void Composite::AddChild(Composite *Next)
{
	this->pComponents.push_back(Next);
}

std::vector<Composite*> Composite::GetNext()
{
	return pComponents;
}

std::vector<Composite*> Composite::GetPrevious()
{
	return PreviousComponents;
}

void Composite::DoThis()
{
	if (this->pComponents.size() == 0)
	{
		return;
	}

	this->pVisitor->Visit(this);
}

void Composite::SetPreviousComponent(Composite* Previous)
{
	this->PreviousComponents.push_back(Previous);
}

int Composite::CountPreviousComponents()
{
	return this->PreviousComponents.size();
}