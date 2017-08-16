#include "State.h"
#include "..\Simulation.h"

State::State(std::shared_ptr<Simulation> pSimulation)
{
	this->pSimulation = pSimulation;
}

void State::Update()
{

}