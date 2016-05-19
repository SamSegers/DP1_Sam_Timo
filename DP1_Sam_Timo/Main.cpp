#include "Filereader.h"
#include "Simulation.h"

int main()
{
	Simulation simulation = Simulation();
	Filereader *f = new Filereader("circuit1.txt");
	f->Read();
	std::cin.get();
	delete f;
	return 1;
}