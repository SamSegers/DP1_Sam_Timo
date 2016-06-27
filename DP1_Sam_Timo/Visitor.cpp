#include "Visitor.h"
#include "Probe.h"
#include "Node.h"
#include "Edge.h"
#include "Input.h"

void Visitor::SetOutput(Output *pView)
{
	this->pView = pView;
}

void Visitor::Visit(Node *pNode)
{
	std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration> start = std::chrono::high_resolution_clock::now();

	if (pNode->ExecuteOperation())
	{
		std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration> finish = std::chrono::high_resolution_clock::now();
		pView->Print("At Component: " + pNode->GetId());
		
		pView->Print("Output of operation is: " + std::to_string(pNode->GetValues().at(0)));
		
		pView->Print("Operation took: " + std::to_string(std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count()) + "ns.");

		for (int i = 0; i < pNode->GetNext().size(); i++)
		{
			pNode->GetNext().at(i)->InsertValue(pNode->GetValues().at(0));
			pNode->GetNext().at(i)->DoThis();
		}

	}
}

void Visitor::Visit(Probe *pProbe)
{
	pView->Print("The final output of probe: " + pProbe->GetId() + " is: " + std::to_string(pProbe->GetValues().at(0)));
}

void Visitor::Visit(Composite *pComposite)
{
	// kijk of het om een edge gaat
	if (pComposite->GetId() != "")
		pView->Print("At Component: " + pComposite->GetId());

	for (int i = 0; i < pComposite->GetNext().size(); i++)
	{
		pComposite->GetNext().at(i)->InsertValue(pComposite->GetValues().at(0));
		pComposite->GetNext().at(i)->DoThis();
	}
}