#include "RunningState.h"
#include "..\Simulation.h"

RunningState::RunningState(std::shared_ptr<Simulation> pSimulation) : State(pSimulation)
{
}

void RunningState::Update()
{
}
