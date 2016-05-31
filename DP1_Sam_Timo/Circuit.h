#ifndef _CIRCUIT_H
#define _CIRCUIT_H

#include <vector>
#include "Factory.h"
#include "Probe.h"
#include "Input.h"
#include "Edge.h"
#include "Component.h"
#include "Output.h"

class Circuit
{
protected:
	Output *pOutput;
	std::vector<Component *> Components;
	
	int ErrorFound(std::string error);
public:
	Circuit();
	~Circuit();

	int CreateNodes(std::vector<std::string>);
	int CreateEdges(std::vector<std::string>);
	int CreateProbes(std::vector<std::string>);
	int CreateInputs(std::vector<std::string>);
	int LinkAll();

	void Start();

};

#endif _CIRCUIT_H