#ifndef _SIMULATION_H
#define _SIMULATION_H

#include "Filereader.h"
#include "Circuit.h"
#include "JsDiagramGenerator.h"

// de simulatie.
// bevat alle hoofdobjecten
class Simulation
{
protected:
	Circuit *pCircuit;
	Filereader *pReader;
	Output *pOutput;
	DiagramGenerator *pDiagram;
	Visitor *pVisitor;

	int Load();
	int CreateCircuit();

	int RunAgain();
	bool ShowDiagram();

	void Init();
	void Cleanup();
public:
	Simulation();
	~Simulation();

	void Start(std::string);
	std::vector<Probe *> StartTest(std::string);
};

#endif