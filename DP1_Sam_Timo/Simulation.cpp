#include "Simulation.h"

Simulation::Simulation()
{
	pOutput = new Output();
	pDiagram = new Diagram();
}

Simulation::~Simulation()
{
	this->Stop();

	if (pReader != nullptr)
	{
		delete pReader;
		pReader = nullptr;
	}

	if (pOutput != nullptr)
	{
		delete pOutput;
		pOutput = nullptr;
	}

	if (pCircuit != nullptr)
	{
		delete pCircuit;
		pCircuit = nullptr;
	}

	if (pDiagram != nullptr)
	{
		delete pDiagram;
		pDiagram = nullptr;
	}
}

int Simulation::Load()
{
	if (pReader->Read())
		return 1;

	return 0;
}

int Simulation::CreateCircuit()
{
	this->pCircuit = new Circuit();
	this->pCircuit->SetOutput(this->pOutput);
	if (!pCircuit->CreateNodes(pReader->GetNodes()) || !pCircuit->CreateInputs(pReader->GetInputs()) || !pCircuit->CreateProbes(pReader->GetProbes()) || !pCircuit->CreateEdges(pReader->GetEdges()))
		return 0;

	return 1;
}

void Simulation::Start(std::string Filename)
{
	this->pReader = new Filereader(Filename);

	if (Load())
	{
		if (CreateCircuit()) {
			pOutput->Print("Initializing the circuit diagram!");
			pDiagram->Create(*pCircuit);
			pOutput->Print("Started the circuit!");
			pCircuit->Start();
		}
		else
			pOutput->Print("Could not create the circuit!");
	}
	else
		pOutput->Print("Failed loading the file!");
	
	
}

void Simulation::Stop()
{

}