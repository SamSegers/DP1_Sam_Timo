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

	while (std::getline(this->_file, Line))
	{
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

		if (
			!PassedNodes && !ReadNodes(Line) || 
			PassedNodes && !ReadEdges(Line)
		)
			return 0; // er is een error ga uit de reader.
	}

	return 1;
}

//TODO remove and unify with Read()
int Filereader::Transform(std::string circuit)
{
	std::string line;

	std::istringstream iss(circuit);

	bool PassedNodes = false;

	while(std::getline(iss, line))
	{
		// comments skip naar de volgende lijn.
		if (line[0] == '#')
			continue;
		
		// lege regel vanaf nu komen de edges.
		if (line == "")
		{
			// vind het lelijk om zo te doen maar het is niet anders.
			PassedNodes = true;
			continue;
		}

		if (
			!PassedNodes && !ReadNodes(line) || 
			PassedNodes && !ReadEdges(line)
		)
			return 0; // er is een error ga uit de reader.
	}

	return 1;
}

int Filereader::ReadNodes(std::string Line)
{
	// kijk om wat het gaat
	if (Line.find("NODE") != std::string::npos)
		return CreateNode(Line);
	else if (Line.find("PROBE") != std::string::npos)
		return CreateProbe(Line);
	else if (Line.find("INPUT") != std::string::npos)
		return CreateInput(Line);
	

	// niet kunnen vinden klopt iets niet.
	return 0;
}

// voeg alles toe bij wat het hoort zodat we het later kunnen maken en linken
int Filereader::ReadEdges(std::string Line)
{
	return CreateEdge(Line);
}

int Filereader::CreateEdge(std::string Line)
{
	this->Edges.push_back(Line);

	return 1;
}

int Filereader::CreateNode(std::string Line)
{
	// store component.

	this->Nodes.push_back(Line);

	return 1;
}

int Filereader::CreateProbe(std::string Line)
{
	this->Probes.push_back(Line);
	return 1;
}

int Filereader::CreateInput(std::string Line)
{
	this->Inputs.push_back(Line);
	return 1;
}

std::vector<std::string> Filereader::GetNodes()
{
	return this->Nodes;
}
std::vector<std::string> Filereader::GetProbes()
{
	return this->Probes;
}
std::vector<std::string> Filereader::GetInputs()
{
	return this->Inputs;
}
std::vector<std::string> Filereader::GetEdges()
{
	return this->Edges;
}