#include "AND.h"
#include <stdint.h>
int AND::ExecuteOperation() {

	if (this->values.size() < 2)
		return 0;
	
	int output = values.at(0) == values.at(1);

	values.clear();
	values.push_back(output);
	
	//DoThis();

	return 1;
}

Component* AND::Clone()
{
	return new AND();
}