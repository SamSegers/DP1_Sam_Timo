#include "Simulation.h"

Simulation::Simulation()
{
	pReader = new Filereader("circuit1.txt");
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
}

int Simulation::Load()
{
	if (pReader->Read())
	{
		return 1;
	}

	return 0;
}

int Simulation::CreateCircuit()
{
	this->pCircuit = new Circuit();

	if (!pCircuit->CreateNodes() || !pCircuit->CreateEdges() || !pCircuit->LinkAll())
		return 0;

	return 1;
}

void Simulation::Start()
{
	if (Load())
	{
		if (CreateCircuit())
		{
			pCircuit->Start();
		}
	}
	
}

void Simulation::Stop()
{

}