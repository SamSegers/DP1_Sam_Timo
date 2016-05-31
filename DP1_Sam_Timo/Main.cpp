#include "Filereader.h"
#include "Simulation.h"

int main()
{
	Simulation simulation = Simulation();
	simulation.Start();
	std::cin.get();

	if (Factory::instance())
	{
		delete Factory::instance();
	}
	return 1;
}