#include "Filereader.h"
#include "Simulation.h"

void Init();
void Cleanup();

int main(int argc, char* argv[])
{
	// factory init
	Init();
	// maak simulatie
	Simulation simulation = Simulation();

	std::string Filename = "";

	// kijk voor meegegeven argumenten
	Filename = argc > 1 ? argv[1] : "circuit1.txt";
	
	// start simulatie.
	simulation.Start(Filename);
	
	std::cin.get();
	// ruim de factory op
	Cleanup();
	
	return 1;
}

void Init()
{
	// vul de factory met classes die we mogelijk willen gebruiken.
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
}

void Cleanup()
{
	// gooi de factory weg
	if (Factory::instance())
	{
		delete Factory::instance();
	}
}