#include "Mediator.h"

Mediator *Mediator::pMediator = nullptr;
Mediator::Mediator()
{

}

Mediator::~Mediator()
{
	
}

Mediator * Mediator::instance()
{
	if (!pMediator)
	{
		pMediator = new Mediator();
	}
	return pMediator;
}

void Mediator::PassValue(Composite * pSource, Composite * pTarget)
{
	pTarget->InsertValue(pSource->GetValues().at(0));
	pTarget->DoThis();
}
