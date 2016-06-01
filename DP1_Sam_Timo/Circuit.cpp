#include "Circuit.h"
#include <exception>

Circuit::Circuit()
{
	pOutput = new Output();
}

Circuit::~Circuit()
{
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


	if (pOutput != nullptr)
	{
		delete pOutput;
		pOutput = nullptr;
	}
}

int Circuit::CreateEdges(std::vector<std::string> Edges)
{
	try
	{
		for (int i = 0; i < Edges.size(); i++)
		{
			Edge *pEdge = (Edge *)Factory::instance()->RequestComponent(_EDGE);

			if (pEdge != nullptr)
			{
				this->Edges.push_back(pEdge);
				return 1;
			}
		}
	}
	catch (int e)
	{
		return ErrorFound("Error in creating edges!");
	}
	return 1;
}

int Circuit::CreateNodes(std::vector<std::string> Nodes)
{
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
	try
	{
		for (int i = 0; i < Inputs.size(); i++)
		{
			Input *pInput = (Input *)Factory::instance()->RequestComponent(_INPUT);

			if (pInput != nullptr)
			{
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
	try
	{
		for (int i = 0; i < Probes.size(); i++)
		{
			Probe *pProbe = (Probe *)Factory::instance()->RequestComponent(_PROBE);

			if (pProbe != nullptr)
			{
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

int Circuit::LinkAll()
{
	try
	{

	}
	catch (int e)
	{
		return ErrorFound("Error in linking the components!");
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

}