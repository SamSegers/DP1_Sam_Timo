#ifndef _SIMULATION_H
#define _SIMULATION_H

#include "Filereader.h"
#include "Circuit.h"

class Simulation
{
protected:
	Circuit *pCircuit;
	Filereader *pReader;
	int Load();
	int CreateCircuit();
public:
	Simulation();
	~Simulation();

	void Start();
	void Stop();
};

#endif