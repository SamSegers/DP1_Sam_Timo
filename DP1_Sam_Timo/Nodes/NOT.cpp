#include "NOT.h"

// voer not uit.
int NOT::ExecuteOperation() 
{
	int output = !values.at(0);
	// zet alles klaar om door te geven.
	values.clear();
	values.push_back(output);

	return 1;
}

Component* NOT::Clone()
{
	return new NOT();
}