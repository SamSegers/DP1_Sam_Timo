#include "NOR.h"
// voer een nor operatie uit
int NOR::ExecuteOperation() {

	// kijk of de waardes aanwezig zijn.
	if (this->values.size() < 2)
		return 0;
	int output = values.at(0) == 0 && values.at(1) == 0;
	// zet alles klaar om door te geven
	values.clear();
	values.push_back(output);
	
	//DoThis();

	return 1;
}

Component* NOR::Clone()
{
	return new NOR();
}