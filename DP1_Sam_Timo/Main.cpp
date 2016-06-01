#include "Filereader.h"
#include "Simulation.h"

void Cleanup();

int main()
{
	Simulation simulation = Simulation();
	simulation.Start();
	std::cin.get();

	Cleanup();
	
	return 1;
}

void Cleanup()
{
	if (Factory::instance())
	{
		delete Factory::instance();
	}
}