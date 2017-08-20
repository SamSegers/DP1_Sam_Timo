#ifndef _STATE_H 
#define _STATE_H
#include <memory>

class Simulation;

class State
{
protected:
	Simulation *pSimulation;
public:
	State(Simulation *pSimulation);
	virtual ~State() {};
	virtual void Update();
};

#endif // !_STATE_H 
