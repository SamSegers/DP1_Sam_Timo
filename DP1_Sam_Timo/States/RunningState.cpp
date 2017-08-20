#include "RunningState.h"
#include "FinishState.h"
#include "..\Simulation.h"

RunningState::RunningState(Simulation *pSimulation) : State(pSimulation)
{
}

void RunningState::Update()
{
	this->pSimulation->Run();
	this->pSimulation->SetState(std::make_shared<FinishState>(this->pSimulation));
}
