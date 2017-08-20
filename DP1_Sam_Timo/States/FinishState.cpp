#include "FinishState.h"
#include "..\Simulation.h"
#include "RunningState.h"

FinishState::FinishState(Simulation *pSimulation) : State(pSimulation)
{
}

void FinishState::Update()
{
	this->pSimulation->Cleanup();

	auto rerun = pSimulation->RunAgain();
	pSimulation->SetRunning(rerun);
	if (rerun)
	{
		pSimulation->SetState(std::make_shared<FinishState>(this->pSimulation));
	}
}
