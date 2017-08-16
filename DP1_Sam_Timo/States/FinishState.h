#ifndef _FINISH_STATE_H
#define _FINISH_STATE_H

#include "State.h"

class FinishState : State
{
protected:

public:
	FinishState(std::shared_ptr<Simulation> pSimulation);
	virtual void Update();

};

#endif // !_FINISH_STATE_H
