#ifndef _SIMULATION_H
#define _SIMULATION_H

#include "Filereader.h"
#include "Circuit.h"
#include "Diagram.h"

class Simulation
{
protected:
	Circuit *pCircuit;
	Filereader *pReader;
	Output *pOutput;
	Diagram *pDiagram;
	Visitor *pVisitor;
	int Load();
	int CreateCircuit();
public:
	Simulation();
	~Simulation();

	void Start(std::string);
	void Stop();
};

#endif