#include "Simulation.h"

Simulation::Simulation()
{
	pOutput = new Output();
	//pReader = new Filereader("circuit1.txt");
}

Simulation::~Simulation()
{
	this->Stop();

	if (pReader != nullptr)
	{
		delete pReader;
		pReader = nullptr;
	}

	if (pCircuit != nullptr)
	{
		delete pCircuit;
		pCircuit = nullptr;
	}

	if (pOutput != nullptr)
	{
		delete pOutput;
		pOutput = nullptr;
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

	if (!pCircuit->CreateNodes(pReader->GetNodes()) || !pCircuit->CreateInputs(pReader->GetInputs()) || !pCircuit->CreateProbes(pReader->GetProbes()) || !pCircuit->CreateEdges(pReader->GetEdges()))
		return 0;

	return 1;
}

void Simulation::Start(std::string Filename)
{
	this->pReader = new Filereader(Filename);

	if (Load())
	{
		if (CreateCircuit())
			pCircuit->Start();
		else
			pOutput->Print("Could not create the circuit!");
	}
	else
		pOutput->Print("Failed loading the file!");
	
	
}

void Simulation::Stop()
{

}