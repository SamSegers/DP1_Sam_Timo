#include "OR.h"

int OR::ExecuteOperation() {

	if (this->values.size() < 2)
		return 0;
	int output = values.at(0) || values.at(1);
	values.clear();
	values.push_back(output);
	
	
	//CallNext();

	return 1;
}

Component* OR::Clone()
{
	return new OR();
}