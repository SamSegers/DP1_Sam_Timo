#ifndef _SIMULATION_H
#define _SIMULATION_H

#include "Filereader.h"
#include "Circuit.h"
#include "Diagram.h"

// de simulatie.
// bevat alle hoofdobjecten
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

	int RunAgain();

	void Init();
	void Cleanup();
public:
	Simulation();
	~Simulation();

	void Start(std::string);
};

#endif