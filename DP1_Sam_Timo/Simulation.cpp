#include "Simulation.h"

Simulation::Simulation()
{
	
}

Simulation::~Simulation()
{
	this->Cleanup();

	
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
	this->pCircuit->SetVisitor(this->pVisitor);
	if (!pCircuit->CreateNodes(pReader->GetNodes()) || !pCircuit->CreateInputs(pReader->GetInputs()) || !pCircuit->CreateProbes(pReader->GetProbes()) || !pCircuit->CreateEdges(pReader->GetEdges()) || !pCircuit->CheckForLinkErrors())
		return 0;

	return 1;
}

void Simulation::Start(std::string Filename)
{
	bool rerun = false;
	while (true)
	{
		this->Init();

		this->pReader = new Filereader(Filename);

		if (Load())
		{
			if (CreateCircuit()) {
				pOutput->Print("Initializing the circuit diagram!");
				if(!rerun) pDiagram->Create(*pCircuit);
				pOutput->Print("Started the circuit!");
				pCircuit->Start();
			}
			else
			{
				pOutput->Print("Could not create the circuit!");
				break;
			}
		}
		else
		{
			pOutput->Print("Failed loading the file!");
			break;
		}

		rerun = RunAgain();
		if (!rerun)
			break;

		this->Cleanup();
	}
}

int Simulation::RunAgain()
{
	pOutput->Print("Run the circuit again? y/n");
	if (pOutput->RunAgain() == "y")
		return 1;
	return 0;
}

void Simulation::Init()
{
	pOutput = new Output();
	pDiagram = new Diagram();
	pVisitor = new Visitor();
	pVisitor->SetOutput(this->pOutput);
}

void Simulation::Cleanup()
{
	if (pReader != nullptr)
	{
		delete pReader;
		pReader = nullptr;
	}

	if (pVisitor != nullptr)
	{
		delete pVisitor;
		pVisitor = nullptr;
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