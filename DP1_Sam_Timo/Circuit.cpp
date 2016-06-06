#include "Circuit.h"
#include <exception>

Circuit::Circuit()
{
	pOutput = new Output();
}

Circuit::~Circuit()
{
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

int Circuit::CreateEdges(std::vector<std::string> Edges)
{
	pOutput->Print("Create edges and link them!");

	try
	{
		for (int i = 0; i < Edges.size(); i++)
		{
			Edge *pEdge = (Edge *)Factory::instance()->RequestComponent(_EDGE);
			
			if (pEdge != nullptr)
				this->Edges.push_back(pEdge);
			else
				throw 1;

			if (!Link(Edges.at(i), pEdge))
				throw 2;

		}
	}
	catch (int e)
	{
		if (e == 1)
			return ErrorFound("Error in creating edges!");
		else if (e == 2)
			return ErrorFound("Error in linking components & edges!");
	}
	return 1;
}

int Circuit::CreateNodes(std::vector<std::string> Nodes)
{
	pOutput->Print("Create nodes!");
	try
	{
		for (int i = 0; i < Nodes.size(); i++)
		{
			std::string Line = Nodes.at(i);

			Node *pNode = nullptr;
			if (Line.find("NAND") != std::string::npos)
				pNode = (Node *)Factory::instance()->RequestComponent(_NAND);
			else if (Line.find("NOT") != std::string::npos)
				pNode = (Node *)Factory::instance()->RequestComponent(_NOT);
			else if (Line.find("XNOR") != std::string::npos)
				pNode = (Node *)Factory::instance()->RequestComponent(_XNOR);
			else if (Line.find("NOR") != std::string::npos)
				pNode = (Node *)Factory::instance()->RequestComponent(_NOR);
			else if (Line.find("XOR") != std::string::npos)
				pNode = (Node *)Factory::instance()->RequestComponent(_XOR);
			else if (Line.find("OR") != std::string::npos)
				pNode = (Node *)Factory::instance()->RequestComponent(_OR);
			else if (Line.find("AND") != std::string::npos)
				pNode = (Node *)Factory::instance()->RequestComponent(_AND);
			else
				throw 1;

			pNode->SetId(Nodes.at(i).substr(0, Nodes.at(i).find(":")));
			
			this->Nodes.push_back(pNode);
		}
	}
	catch (int e)
	{
		return ErrorFound("Error in creating nodes!");
	}

	return 1;
}

int Circuit::CreateInputs(std::vector<std::string> Inputs)
{
	pOutput->Print("Create inputs!");
	try
	{
		for (int i = 0; i < Inputs.size(); i++)
		{
			Input *pInput = (Input *)Factory::instance()->RequestComponent(_INPUT);

			if (Inputs.at(i).find("INPUT_HIGH") != std::string::npos)
				pInput->InsertValue(1);
			else if (Inputs.at(i).find("INPUT_LOW") != std::string::npos)
				pInput->InsertValue(0);
			else
				throw 1;

			if (pInput != nullptr)
			{
				pInput->SetId(Inputs.at(i).substr(0, Inputs.at(i).find(":")));
				this->Inputs.push_back(pInput);
			}
			else
				throw 1;
		}
	}
	catch (int e)
	{
		return ErrorFound("Error in creating inputs!");
	}

	return 1;
}

int Circuit::CreateProbes(std::vector<std::string> Probes)
{
	pOutput->Print("Create probes!");
	try
	{
		for (int i = 0; i < Probes.size(); i++)
		{
			Probe *pProbe = (Probe *)Factory::instance()->RequestComponent(_PROBE);

			if (pProbe != nullptr)
			{
				pProbe->SetId(Probes.at(i).substr(0, Probes.at(i).find(":")));
				this->Probes.push_back(pProbe);
			}
			else
				throw 1;
		}
	}
	catch (int e)
	{
		return ErrorFound("Error in creating probes!");
	}

	return 1;
}

int Circuit::Link(std::string Data, Edge *pEdge)
{
	if (Data.find(":") != std::string::npos)
	{
		std::string id = Data.substr(0, Data.find(":"));

		int found = 0;

		for (int i = 0; i < Inputs.size(); i++)
			if (Inputs.at(i)->GetId() == id)
			{
			found = 1;
			Inputs.at(i)->AddNext(pEdge);
			}
		for (int i = 0; i < Nodes.size(); i++)
			if (Nodes.at(i)->GetId() == id)
			{
			found = 1;
			Nodes.at(i)->AddNext(pEdge);
			}

		if (!found)
		{
			pOutput->Print("Linking failed!");
			return 0;
		}
		// reset
		found = 0;
		id = "";
		// haal al de info uit de string voor linking
		Data = Data.substr(Data.find("\t")+1);

		while (true)
		{
			if (Data.find(",") != std::string::npos)
			{
				id = Data.substr(0, Data.find(","));
				Data = Data.substr(Data.find(",") + 1);
			
				for (int i = 0; i < Nodes.size(); i++)
					if (Nodes.at(i)->GetId() == id)
					{
						found = 1;
						pEdge->AddNext(Nodes.at(i));
					}
				for (int i = 0; i < Probes.size(); i++)
					if (Probes.at(i)->GetId() == id)
					{
						found = 1;
						pEdge->AddNext(Probes.at(i));
					}

				if (!found)
				{
					pOutput->Print("Linking failed!");
					return 0;
				}

			}
			else if (Data.find(";") != std::string::npos)
			{
				if (Data.find("\t") != std::string::npos)
				{
					Data = Data.substr(Data.find("\t")+1);
				}

				id = Data.substr(0, Data.find(";"));

				for (int i = 0; i < Nodes.size(); i++)
					if (Nodes.at(i)->GetId() == id)
					{
						found = 1;
						pEdge->AddNext(Nodes.at(i));
					}
				for (int i = 0; i < Probes.size(); i++)
					if (Probes.at(i)->GetId() == id)
					{
						found = 1;
						pEdge->AddNext(Probes.at(i));
					}

				if (!found)
				{
					pOutput->Print("Linking failed!");
					return 0;
				}

				break;
			}
			else
				return 0;
		}
	}

	return 1;
}

int Circuit::ErrorFound(std::string error = "")
{
	this->pOutput->Print(error);

	return 0;
}

void Circuit::Start()
{
	for (int i = 0; i < Inputs.size(); i++)
	{
		std::thread t(&Input::CallNext, Inputs.at(i));
		t.detach();
		//Inputs.at(i)->CallNext();
	}
}