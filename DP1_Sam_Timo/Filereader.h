#ifndef _FILEREADER_H
#define _FILEREADER_H

#include <fstream>
#include <sstream>
#include <istream>
#include <iostream>
#include "Factory.h"
#include "Probe.h"
#include "Input.h"
#include "Edge.h"

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

	std::vector<Node *> Nodes;
	std::vector<Probe *>Probes;
	std::vector<Input *>Inputs;
	std::vector<Edge *>Edges;

public:
	Filereader(std::string Path);
	~Filereader();
	int Read();

	std::vector<Node *> GetNodes();
	std::vector<Probe *> GetProbes();
	std::vector<Input *> GetInputs();
	std::vector<Edge *> GetEdges();
};

#endif // _FILEREADER_H