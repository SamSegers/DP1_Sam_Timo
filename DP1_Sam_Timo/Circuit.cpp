#include "Circuit.h"
#include <exception>

Circuit::Circuit()
{
	pOutput = new Output();
}

Circuit::~Circuit()
{
	for (int i = 0; i < this->Components.size(); i++)
	{
		Component *pComponent = Components.at(i);

		if (pComponent != nullptr)
		{
			delete pComponent;
			Components.at(i) = nullptr;
			pComponent = nullptr;
		}
	}

	Components.clear();

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
			/*Edge *pEdge = (Edge *)Factory::RequestComponent(EDGE);

			if (pEdge != nullptr)
			{
			this->Edges.push_back(pEdge);
			return 1;
			}*/
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
			/*Node *pNode = nullptr;
			if (Line.find("NAND") != std::string::npos)
				pNode = (Node *)Factory::RequestComponent(NAND);
			else if (Line.find("NOT") != std::string::npos)
				pNode = (Node *)Factory::RequestComponent(NOT);
			else if (Line.find("XNOR") != std::string::npos)
				pNode = (Node *)Factory::RequestComponent(XNOR);
			else if (Line.find("NOR") != std::string::npos)
				pNode = (Node *)Factory::RequestComponent(NOR);
			else if (Line.find("XOR") != std::string::npos)
				pNode = (Node *)Factory::RequestComponent(XOR);
			else if (Line.find("OR") != std::string::npos)
				pNode = (Node *)Factory::RequestComponent(OR);
			else if (Line.find("AND") != std::string::npos)
				pNode = (Node *)Factory::RequestComponent(AND);
			else
				return 0;*/
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
			/*Input *pInput = (Input *)Factory::RequestComponent(INPUT);

			if (pInput != nullptr)
			{
				this->Inputs.push_back(pInput);
				return 1;
			}*/
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
			/*Probe *pProbe = (Probe *)Factory::RequestComponent(PROBE);

			if (pProbe != nullptr)
			{
				this->Probes.push_back(pProbe);
				return 1;
			}*/
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