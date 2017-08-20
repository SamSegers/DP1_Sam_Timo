#ifndef _RUNNING_STATE_H
#define _RUNNING_STATE_H

#include "State.h"

class RunningState : public State
{
protected:

public:
	RunningState(Simulation *pSimulation);
	virtual void Update();

};

#endif // !_RUNNING_STATE_H
