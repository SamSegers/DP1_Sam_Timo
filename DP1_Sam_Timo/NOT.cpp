#include "NOT.h"


int NOT::ExecuteOperation() 
{
	int output = !values.at(0);
	values.clear();
	values.push_back(output);
	
	
	//DoThis();

	return 1;
}

Component* NOT::Clone()
{
	return new NOT();
}