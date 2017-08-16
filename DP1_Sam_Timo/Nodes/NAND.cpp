#include "NAND.h"

// voer een nand operatie uit
int NAND::ExecuteOperation() {

	// kijk of de waardes aanwezig zijn.
	if (this->values.size() < 2)
		return 0;
	int output = values.at(0)!=1 || values.at(1)!=1;
	// zet alles klaar om door te geven
	values.clear();
	values.push_back(output);

	return 1;
}

Component* NAND::Clone()
{
	return new NAND();
}
