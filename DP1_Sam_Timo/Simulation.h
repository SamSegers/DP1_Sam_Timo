#ifndef _SIMULATION_H
#define _SIMULATION_H

#include "Filereader.h"
#include "Circuit.h"
#include "CppDiagramGenerator.h"
#include "JsDiagramGenerator.h"
#include "States\State.h"

// de simulatie.
// bevat alle hoofdobjecten
class Simulation
{
protected:
	std::shared_ptr<State> pState;
	std::shared_ptr<Circuit> pCircuit;
	Filereader* pReader;
	std::shared_ptr<Output> pOutput;
	std::shared_ptr<DiagramGenerator> pDiagramGenerator;
	std::shared_ptr<Visitor> pVisitor;

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
	void SetState(std::shared_ptr<State> pState);
};

#endif