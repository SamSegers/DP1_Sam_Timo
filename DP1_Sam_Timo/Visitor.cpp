#include "Visitor.h"
#include "Probe.h"
#include "Composite\Edge.h"
#include "Input.h"
#include "Mediator.h"

void Visitor::SetOutput(std::shared_ptr<Output> pView)
{
	this->pView = pView;
}

void Visitor::Visit(Node* pNode)
{
	// time hoe lang een operatie duurt.
	auto start = std::chrono::high_resolution_clock::now();

	if (pNode->ExecuteOperation())
	{
		auto finish = std::chrono::high_resolution_clock::now();
		// print alles
		pView->Print("At Component: " + pNode->GetId());
		
		pView->Print("Output of operation is: " + std::to_string(pNode->GetValues().at(0)));
		
		pView->Print("Operation took: " + std::to_string(std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count()) + "ns.");

		// gaan naar de volgende.
		for (int i = 0; i < pNode->GetNext().size(); i++)
		{
			Mediator::instance()->PassValue(pNode, (Node *)pNode->GetNext().at(i));
		}

	}
}

// weergeef output van probe
void Visitor::Visit(Probe* pProbe)
{
	pView->Print("The final output of probe: " + pProbe->GetId() + " is: " + std::to_string(pProbe->GetValues().at(0)));
}

// zorg dat de volgende in de lijst word aangeroepen
void Visitor::Visit(Composite* pComposite)
{
	// kijk of het om een edge gaat
	if (pComposite->GetId() != "")
		pView->Print("At Component: " + pComposite->GetId());

	for (int i = 0; i < pComposite->GetNext().size(); i++)
	{
		Mediator::instance()->PassValue(pComposite, pComposite->GetNext().at(i));
	}
}