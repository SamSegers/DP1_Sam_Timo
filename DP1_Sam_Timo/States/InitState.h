#ifndef _INIT_STATE_H 
#define _INIT_STATE_H

#include "State.h"

class InitState : public State
{
protected:

public:
	InitState(Simulation *pSimulation);
	virtual void Update();
};

#endif // !_INIT_STATE_H 
