#ifndef _STATE_H 
#define _STATE_H
#include <memory>

class Simulation;

class State
{
protected:
	std::shared_ptr<Simulation> pSimulation;
public:
	State(std::shared_ptr<Simulation> pSimulation);
	virtual void Update();
};

#endif // !_STATE_H 
