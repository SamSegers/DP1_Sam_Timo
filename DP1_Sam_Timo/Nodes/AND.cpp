#include "AND.h"
#include <stdint.h>

// voer een and operatie uit
int AND::ExecuteOperation() {

	// kijk of de waardes aanwezig zijn.
	if (this->values.size() < 2)
		return 0;
	
	int output = values.at(0) == 1 && values.at(1) == 1;

	// zet alles klaar om door te geven
	values.clear();
	values.push_back(output);
	
	//DoThis();

	return 1;
}

Component* AND::Clone()
{
	return new AND();
}