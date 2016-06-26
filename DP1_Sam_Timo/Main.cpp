#include "Filereader.h"
#include "Simulation.h"

void Cleanup();
int main(int argc, char* argv[])
{

	Factory::instance()->AddComponent(new Node());
	Factory::instance()->AddComponent(new Edge());
	Factory::instance()->AddComponent(new Input());
	Factory::instance()->AddComponent(new Probe());
	Factory::instance()->AddComponent(new AND());
	Factory::instance()->AddComponent(new NAND());
	Factory::instance()->AddComponent(new NOR());
	Factory::instance()->AddComponent(new NOT());
	Factory::instance()->AddComponent(new OR());
	Factory::instance()->AddComponent(new XNOR());
	Factory::instance()->AddComponent(new XOR());

	Simulation simulation = Simulation();

	std::string Filename = "";

	if (argc > 1)
		Filename = argv[1];
	else
		Filename = "circuit1.txt";
	
	simulation.Start(Filename);
	
	std::cin.get();
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