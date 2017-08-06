#include "Mediator.h"

Mediator *Mediator::pMediator = nullptr;
Mediator::Mediator()
{

}

Mediator::~Mediator()
{
	for (int i = 0; i < _nodes.size(); i++)
	{
		if (_nodes.at(i) != nullptr)
		{
			Node *pNode = _nodes.at(i);
			delete pNode;
		}
	}

	_nodes.clear();
}

Mediator * Mediator::instance()
{
	if (!pMediator)
	{
		pMediator = new Mediator();
	}
	return pMediator;
}

void Mediator::PassValue(Node * pSource, Node * pTarget)
{
	pTarget->InsertValue(pSource->GetValues().at(0));
	pTarget->DoThis();
}
