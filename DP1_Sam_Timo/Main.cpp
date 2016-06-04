#include "Filereader.h"
#include "Simulation.h"

void Cleanup();
std::mutex _mutex;
int main(int argc, char* argv[])
{
	
	Simulation simulation = Simulation();

	std::string Filename = "";

	if (argc > 1)
		Filename = argv[1];
	else
		Filename = "circuit1.txt";
	
	simulation.Start(Filename);
	
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