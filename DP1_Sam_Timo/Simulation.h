#ifndef _SIMULATION_H
#define _SIMULATION_H

#include "Filereader.h"
#include "Circuit.h"
#include "DiagramGeneration\CppGenerator.h"
#include "States\State.h"

// de simulatie.
// bevat alle hoofdobjecten
class Simulation
{
protected:
	bool _running = true;
	std::string _fileName;
	std::shared_ptr<State> pState;
	std::shared_ptr<Circuit> pCircuit;
	Filereader* pReader;
	std::shared_ptr<Output> pOutput;
	std::shared_ptr<DiagramGeneration::Generator> pDiagramGenerator;
	std::shared_ptr<Visitor> pVisitor;

	bool ShowDiagram();
	
public:
	Simulation();
	~Simulation();

	void Start(std::string);
	std::vector<Probe *> StartTest(std::string);
	void SetState(std::shared_ptr<State> pState);
	void Cleanup();
	void SetRunning(bool running);
	void Init();
	int Load();
	void FailedLoad();
	void FailedCircuit();
	int CreateCircuit();
	int RunAgain();
	void Run();
};

#endif