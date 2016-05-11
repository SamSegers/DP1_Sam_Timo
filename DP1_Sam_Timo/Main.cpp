#include "Filereader.h"

int main()
{

	Filereader *f = new Filereader("circuit1.txt");
	f->Read();
	delete f;
	std::cin.get();
	return 1;
}