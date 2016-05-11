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

	return 1;
}

int Filereader::CreateNode(std::string Line)
{
	return 1;
}

int Filereader::CreateProbe(std::string Line)
{
	return 1;
}

int Filereader::CreateInput(std::string Line)
{
	return 1;
}