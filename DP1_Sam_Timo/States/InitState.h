#ifndef _INIT_STATE_H 
#define _INIT_STATE_H

#include "State.h"

class InitState : State
{
protected:

public:
	InitState(std::shared_ptr<Simulation> pSimulation);
	virtual void Update();
};

#endif // !_INIT_STATE_H 
