#include "NAND.h"

int NAND::ExecuteOperation() {

	if (this->values.size() < 2)
		return 0;
	int output = values.at(0)!=1 || values.at(1)!=1;

	values.clear();
	values.push_back(output);

	//DoThis();
	return 1;
}

Component* NAND::Clone()
{
	return new NAND();
}
