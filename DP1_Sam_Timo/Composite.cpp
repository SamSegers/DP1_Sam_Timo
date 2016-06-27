#include "Composite.h"

// ruim alles op
Composite::~Composite()
{
	this->pComponents.clear();
	this->PreviousComponents.clear();
}

// voeg een volgende composite toe
void Composite::AddChild(Composite *Next)
{
	this->pComponents.push_back(Next);
}

// haal alle volgende op.
std::vector<Composite*> Composite::GetNext()
{
	return pComponents;
}
// haal alle vorige op.
std::vector<Composite*> Composite::GetPrevious()
{
	return PreviousComponents;
}

// ga naar de volgende en als het een node is zal de visitor zijn operatie uitvoeren.
void Composite::DoThis()
{
	if (this->pComponents.size() == 0)
	{
		return;
	}

	this->pVisitor->Visit(this);
}

// voeg de vorige toe.
void Composite::SetPreviousComponent(Composite* Previous)
{
	this->PreviousComponents.push_back(Previous);
}