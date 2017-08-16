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
	return pReader->Read();
}

// maak een circuit
int Simulation::CreateCircuit()
{
	this->pCircuit = std::make_shared<Circuit>();
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
		this->pReader = Filereader::CreateFilereader(Filename);

		// laad data uit de file
		if (Load())
		{
			// maak circuit
			if (CreateCircuit()) {
				pOutput->Print("Initializing the circuit diagram!");
				pOutput->Print("Started the circuit!");
				pCircuit->Start();
				if(ShowDiagram()) 
					pDiagramGenerator->Generate(*pCircuit);
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

// wordt gebruikt voor unit tests
// alles zonder checks uitvoeren om de errors te krijgen
std::vector<Probe *> Simulation::StartTest(std::string circuit)
{
	this->pReader = Filereader::CreateStringreader(circuit);
	this->Init();
	pReader->Read();
	// het liefst zou ik hier CreateCircuit() aanroepen, maar dat gaat even niet omdat de inputs automatisch gezet moeten worden
	this->pCircuit = std::make_shared<Circuit>();
	this->pCircuit->SetInputs(1, 0);
	this->pCircuit->SetOutput(this->pOutput);
	this->pCircuit->SetVisitor(this->pVisitor);
	this->pCircuit->CreateNodes(pReader->GetNodes());
	this->pCircuit->CreateInputs(pReader->GetInputs());
	this->pCircuit->CreateProbes(pReader->GetProbes());
	this->pCircuit->CreateEdges(pReader->GetEdges());
	std::vector<Probe *> probes = pCircuit->Start();
	return probes;
}

bool Simulation::ShowDiagram()
{
	pOutput->Print("Generate diagram? y/n");
	return pOutput->RunAgain() == "y";
}

// vraag of we nog een keer willen
int Simulation::RunAgain()
{
	pOutput->Print("Run the circuit again? y/n");
	return pOutput->RunAgain() == "y";
}

// init alles
void Simulation::Init()
{
	pOutput = std::make_shared<Output>();
	pDiagramGenerator = std::make_shared<CppDiagramGenerator>();
	pVisitor = std::make_shared<Visitor>();
	pVisitor->SetOutput(this->pOutput);
}

void Simulation::Cleanup()
{
	if (pReader != nullptr)
	{
		delete pReader;
		pReader = nullptr;
	}
}

void Simulation::SetState(std::shared_ptr<State> pState)
{
	this->pState = pState;
}
