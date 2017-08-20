#ifndef _FINISH_STATE_H
#define _FINISH_STATE_H

#include "State.h"

class FinishState : public State
{
protected:

public:
	FinishState(Simulation *pSimulation);
	~FinishState() {}
	virtual void Update();

};

#endif // !_FINISH_STATE_H
