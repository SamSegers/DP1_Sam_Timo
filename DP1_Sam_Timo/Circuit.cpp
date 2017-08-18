#include "Circuit.h"
#include <exception>
#include <map>
#include <typeinfo>

Circuit::Circuit()
{
	this->_inputsSet = false;
}

Circuit::~Circuit()
{
	
	// ruim alle edges op.
	for (int i = 0; i < this->Edges.size(); i++)
	{
		Edge *pEdge = Edges.at(i);

		if (pEdge != nullptr)
		{
			delete pEdge;
			Edges.at(i) = nullptr;
			pEdge = nullptr;
		}
	}

	Edges.clear();
	// ruim alle probes op.
	for (int i = 0; i < this->Probes.size(); i++)
	{
		Probe *pProbe = Probes.at(i);

		if (pProbe != nullptr)
		{
			delete pProbe;
			Probes.at(i) = nullptr;
			pProbe = nullptr;
		}
	}

	Probes.clear();
	// ruim inputs op.
	for (int i = 0; i < this->Inputs.size(); i++)
	{
		Input *pInput = Inputs.at(i);

		if (pInput != nullptr)
		{
			delete pInput;
			Inputs.at(i) = nullptr;
			pInput = nullptr;
		}
	}

	Inputs.clear();
	// ruim nodes op.
	for (int i = 0; i < this->Nodes.size(); i++)
	{
		Node *pNode = Nodes.at(i);
		
		if (pNode != nullptr)
		{
			delete pNode;
			Nodes.at(i) = nullptr;
			pNode = nullptr;
		}
	}

	Nodes.clear();
}

// maak een edge aan de hand van de data uit de filereader.
int Circuit::CreateEdges(std::vector<std::string> Edges)
{
	pView->Print("Create edges and link them!");

	try
	{
		for (int i = 0; i < Edges.size(); i++)
		{
			// maak de edge
			Edge *pEdge = (Edge *)Factory::instance()->RequestComponent(_EDGE);
			
			// zet in lijst.
			if (pEdge != nullptr)
				this->Edges.push_back(pEdge);
			else
				throw 1;

			// link de edge
			if (!Link(Edges.at(i), pEdge))
				throw 2;

		}
	}
	catch (int e)
	{
		// file heeft fouten?
		if (e == 1)
			return ErrorFound("Error in creating edges!");
		else if (e == 2)
			return ErrorFound("Error in linking components & edges!");
	}
	return 1;
}

// maakt nodes aan uit de filereader.
int Circuit::CreateNodes(std::vector<std::string> Nodes)
{
	pView->Print("Create nodes!");
	try
	{
		for (int i = 0; i < Nodes.size(); i++)
		{
			std::string Line = Nodes.at(i);

			Node *pNode = nullptr;

			std::map<std::string, uint> nodeTypes = {
				{"AND", _AND}, {"NAND", _NAND}, {"NOR", _NOR}, {"NOT", _NOT}, {"OR", _OR}, {"XNOR", _XNOR}, {"XOR", _XOR}
			};

			// maak desbetreffende node aan.
			for (auto const& nodeType : nodeTypes) {
				if (Line.find(nodeType.first) != std::string::npos)
					pNode = (Node *)Factory::instance()->RequestComponent(nodeType.second);
			}

			// node is niet gemaakt geef error
			if (pNode == nullptr)
				throw 1;

			// zet id 
			pNode->SetId(Nodes.at(i).substr(0, Nodes.at(i).find(":")));
			this->Nodes.push_back(pNode);
		}
	}
	catch (int e)
	{
		// nodes konden niet gemaakt worden
		return ErrorFound("Error in creating nodes!");
	}

	return 1;
}

// maak inputs
int Circuit::CreateInputs(std::vector<std::string> Inputs)
{
	if (!this->_inputsSet) {
		// vraag voor de input waardes
		this->_high = pView->AskForInputHigh();
		this->_low = pView->AskForInputLow();
		this->_inputsSet = true;
	}

	pView->Print("Create inputs!");
	try
	{
		for (int i = 0; i < Inputs.size(); i++)
		{
			// maak input
			Input *pInput = (Input *)Factory::instance()->RequestComponent(_INPUT);

			// zet de input waardes
			if (Inputs.at(i).find("INPUT_HIGH") != std::string::npos)
			{	
				pInput->InsertValue(this->_high);
			}
			else if (Inputs.at(i).find("INPUT_LOW") != std::string::npos)
			{
				pInput->InsertValue(this->_low);
			}
			else
				throw 1; // error

			if (pInput != nullptr)
			{
				// zet id
				pInput->SetId(Inputs.at(i).substr(0, Inputs.at(i).find(":")));
				this->Inputs.push_back(pInput);
			}
			else
				throw 1;
		}
	}
	catch (int e)
	{
		// input kon niet gemaakt worden
		return ErrorFound("Error in creating inputs!");
	}

	return 1;
}

// maak probes
int Circuit::CreateProbes(std::vector<std::string> Probes)
{
	pView->Print("Create probes!");
	try
	{
		for (int i = 0; i < Probes.size(); i++)
		{
			// maak een probe
			Probe *pProbe = (Probe *)Factory::instance()->RequestComponent(_PROBE);

			if (pProbe != nullptr)
			{
				// zet de probe id.
				pProbe->SetId(Probes.at(i).substr(0, Probes.at(i).find(":")));
				this->Probes.push_back(pProbe);
			}
			else
				throw 1;
		}
	}
	catch (int e)
	{
		// probe error
		return ErrorFound("Error in creating probes!");
	}

	return 1;
}

// link alles aan elkaar
int Circuit::Link(std::string Data, Edge *pEdge)
{
	if (Data.find(":") != std::string::npos) 
	{
		std::string id = Data.substr(0, Data.find(":"));

		std::vector<Composite*> components;
		components.reserve(Inputs.size() + Nodes.size() + Probes.size()); // preallocate memory
		components.insert(components.end(), Inputs.begin(), Inputs.end());
		components.insert(components.end(), Nodes.begin(), Nodes.end());
		components.insert(components.end(), Probes.begin(), Probes.end());

		if (!LinkAdd(components, pEdge, id, false))
			return 0;

		// haal al de info uit de string voor linking
		Data = Data.substr(Data.find("\t") + 1);

		while (true)
		{
			// kijk of we naar het volgende object moeten of naar de volgende lijn.
			bool comma = Data.find(",") != std::string::npos;
			if (comma || Data.find(";") != std::string::npos)
			{
				if (comma) 
				{
					id = Data.substr(0, Data.find(","));
					Data = Data.substr(Data.find(",") + 1);
				}
				else 
				{
					if (Data.find("\t") != std::string::npos)
						Data = Data.substr(Data.find("\t") + 1);

					id = Data.substr(0, Data.find(";"));
				}
				// link aan een edge.
				if (!LinkAdd(components, pEdge, id, true))
					return 0;

				if(!comma)
					break;
			}
			else
				return 0;
		}
	}

	return 1;
}

// linken aan een edge
int Circuit::LinkAdd(std::vector<Composite*> components, Edge *pEdge, std::string id, bool toEdge)
{
	int found = 0;
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->GetId() == id)
		{
			found = 1;

			// linken in view weergeven
			for (int j = 0; j < pEdge->GetPrevious().size(); j++)
			{
				// print waar alles aan gelinkt is
				pView->Print("Linking " + pEdge->GetPrevious().at(j)->GetId()  + " to " + components[i]->GetId());
			}

			// voer de link daadwerkelijk uit.
			if (toEdge)
			{
				pEdge->AddChild(components[i]);
				components[i]->SetPreviousComponent(pEdge);
			}
			else
			{
				components[i]->AddChild(pEdge);
				pEdge->SetPreviousComponent(components[i]);
			}
		}
	}
	
	// fout in het linken
	if(!found)
		pView->Print("Linking failed: no component '" + id + "' found!");

	return found;
}

// print de error.
int Circuit::ErrorFound(std::string error = "")
{
	this->pView->Print(error);

	return 0;
}

std::vector<Probe *> Circuit::Start()
{
	// aparte class misschien moeten zijn voor timen.
	// tel de tijd in ns.
	auto start = std::chrono::high_resolution_clock::now();
	
	// start en begin bij inputs.
	for (int i = 0; i < Inputs.size(); i++)
	{
		Inputs.at(i)->Accept(std::make_shared<Visitor>());
	}

	auto finish = std::chrono::high_resolution_clock::now();
	
	this->CheckIfCircuitWasSuccessful();

	pView->Print("Circuit took: " + std::to_string(std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count()) + "ns.");

	return this->Probes;
}

// kijk of er iets niet klopte in het circuit tijdens runtime.
void Circuit::CheckIfCircuitWasSuccessful()
{
	_isSuccesful = true;

	for (int i = 0; i < this->Probes.size(); i++)
	{
		if (this->Probes.at(i)->GetValues().size() == 0)
		{
			_isSuccesful = false;
			pView->Print("The circuit failed!");
			break;
		}
	}
}

std::vector<Input*> Circuit::GetInputs() {
	return Inputs;
}

// wordt gebruikt voor unittests waar niet om waarden gevraagd wordt
void Circuit::SetInputs(int high, int low) {
	this->_high = high;
	this->_low = low;
	this->_inputsSet = true;
}

void Circuit::SetVisitor(std::shared_ptr<Visitor> pVisitor)
{
	this->pVisitor = pVisitor;
}

void Circuit::SetOutput(std::shared_ptr<Output> pView)
{
	this->pView = pView;
}

bool Circuit::IsSuccesful()
{
	return _isSuccesful;
}