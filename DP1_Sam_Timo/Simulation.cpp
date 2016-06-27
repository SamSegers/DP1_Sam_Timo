#include "Simulation.h"

Simulation::Simulation()
{
	
}

Simulation::~Simulation()
{
	this->Cleanup();

	
}

// laat file reader de file lezen.
int Simulation::Load()
{
	if (pReader->Read())
		return 1;

	return 0;
}

// maak een circuit
int Simulation::CreateCircuit()
{
	this->pCircuit = new Circuit();
	this->pCircuit->SetOutput(this->pOutput);
	this->pCircuit->SetVisitor(this->pVisitor);
	// kijk of alles klopt
	if (!pCircuit->CreateNodes(pReader->GetNodes()) || !pCircuit->CreateInputs(pReader->GetInputs()) || !pCircuit->CreateProbes(pReader->GetProbes()) || !pCircuit->CreateEdges(pReader->GetEdges()))
		return 0;

	return 1;
}

// start de circuit.
void Simulation::Start(std::string Filename)
{
	bool rerun = false;
	// loop omdat we mogelijk opnieuw willen
	while (true)
	{
		// init circuit en alles
		this->Init();

		// zet de file
		this->pReader = new Filereader(Filename);

		// laad data uit de file
		if (Load())
		{
			// maak circuit
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

		// opnieuw?
		rerun = RunAgain();
		if (!rerun)
			break;

		// ruim alles op
		this->Cleanup();
	}
}

// vraag of we nog een keer willen
int Simulation::RunAgain()
{
	pOutput->Print("Run the circuit again? y/n");
	if (pOutput->RunAgain() == "y")
		return 1;
	return 0;
}

// init alles
void Simulation::Init()
{
	pOutput = new Output();
	pDiagram = new Diagram();
	pVisitor = new Visitor();
	pVisitor->SetOutput(this->pOutput);
}

// ruim alles op.
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