#ifndef _RUNNING_STATE_H
#define _RUNNING_STATE_H

#include "State.h"

class RunningState : State
{
protected:

public:
	RunningState(std::shared_ptr<Simulation> pSimulation);
	virtual void Update();

};

#endif // !_RUNNING_STATE_H
