#include "Filereader.h"

Filereader::Filereader(std::string Path)
{
	this->_path = Path;
}

Filereader::~Filereader()
{
	this->_path = "";
}

int Filereader::Read()
{
	std::string Line;

	this->_file = std::ifstream(this->_path);

	bool PassedNodes = false;

	while (!this->_file.eof())
	{
		std::getline(this->_file,Line);

		// comments skip naar de volgende lijn.
		if (Line[0] == '#')
			continue;
		
		// lege regel vanaf nu komen de edges.
		if (Line == "")
		{
			// vind het lelijk om zo te doen maar het is niet anders.
			PassedNodes = true;
			continue;
		}

		if (!PassedNodes)
			if (!ReadNodes(Line))
				return 0; // er is een error ga uit de reader.
		if (PassedNodes)
			if (!ReadEdges(Line))
				return 0; // er is een error ga uit de reader.
	}

	return 1;
}


int Filereader::ReadNodes(std::string Line)
{
	if (Line.find("NODE") != std::string::npos)
		return CreateNode(Line);
	else if (Line.find("PROBE") != std::string::npos)
		return CreateProbe(Line);
	else if (Line.find("INPUT") != std::string::npos)
		return CreateInput(Line);
	
	// niet kunnen vinden klopt iets niet.
	return 0;
}

int Filereader::ReadEdges(std::string Line)
{
	return CreateEdge(Line);
}

int Filereader::CreateEdge(std::string Line)
{
	Edge *pEdge = (Edge *)Factory::RequestComponent(EDGE);

	if (pEdge != nullptr)
	{
		this->Edges.push_back(pEdge);
		return 1;
	}

	return 0;
}

int Filereader::CreateNode(std::string Line)
{
	Node *pNode = nullptr;
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
		return 0;
	// store component.

	return 1;
}

int Filereader::CreateProbe(std::string Line)
{
	Probe *pProbe = (Probe *)Factory::RequestComponent(PROBE);

	if (pProbe != nullptr)
	{
		this->Probes.push_back(pProbe);
		return 1;
	}

	return 0;
}

int Filereader::CreateInput(std::string Line)
{
	Input *pInput = (Input *)Factory::RequestComponent(INPUT);

	if (pInput != nullptr)
	{
		this->Inputs.push_back(pInput);
		return 1;
	}

	return 0;
}

std::vector<Node *> Filereader::GetNodes()
{
	return this->Nodes;
}
std::vector<Probe *> Filereader::GetProbes()
{
	return this->Probes;
}
std::vector<Input *> Filereader::GetInputs()
{
	return this->Inputs;
}
std::vector<Edge *> Filereader::GetEdges()
{
	return this->Edges;
}