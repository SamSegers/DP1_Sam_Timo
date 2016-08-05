#ifndef _FILEREADER_H
#define _FILEREADER_H

#include <fstream>
#include <sstream>
#include <istream>
#include <iostream>
#include <vector>
#include <string>

// leest de file uit en zet vervolgens waar alles bij hoort.
class Filereader
{
protected:
	std::ifstream _file;
	std::string _path;

	int ReadNodes(std::string);
	int ReadEdges(std::string);
	
	int CreateEdge(std::string);
	int CreateNode(std::string);
	int CreateProbe(std::string);
	int CreateInput(std::string);

	std::vector<std::string> Nodes;
	std::vector<std::string>Probes;
	std::vector<std::string>Inputs;
	std::vector<std::string>Edges;

public:
	Filereader(std::string Path);
	~Filereader();

	int Read();
	int Transform(std::string circuit);

	std::vector<std::string> GetNodes();
	std::vector<std::string> GetProbes();
	std::vector<std::string> GetInputs();
	std::vector<std::string> GetEdges();
};

#endif // _FILEREADER_H