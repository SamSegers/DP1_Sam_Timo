#include "InitState.h"
#include "..\Simulation.h"
#include "RunningState.h"
#include "FinishState.h"

InitState::InitState(Simulation *pSimulation) : State(pSimulation)
{

}

void InitState::Update()
{
	pSimulation->Init();
	auto loadFailed = pSimulation->Load();
	auto circuitFailed = pSimulation;
	if (circuitFailed && loadFailed)
	{
		this->pSimulation->SetState(std::make_shared<RunningState>(this->pSimulation));
	}
	else
	{
		if(loadFailed)
			this->pSimulation->FailedLoad();
		if (circuitFailed)
			this->pSimulation->FailedCircuit();
		this->pSimulation->SetState(std::make_shared<FinishState>(this->pSimulation));
	}
}
