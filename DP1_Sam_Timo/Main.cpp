#include "Filereader.h"

int main()
{
	Filereader *f = new Filereader("circuit1.txt");
	f->Read();
	std::cin.get();
	delete f;
	return 1;
}