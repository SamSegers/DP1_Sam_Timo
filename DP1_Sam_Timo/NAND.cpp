#include "NAND.h"

int NAND::ExecuteOperation() {

	if (this->values.size() < 2)
		return 0;

	int output = values.at(0)!=1 || values.at(1)!=1;
	values.clear();
	values.push_back(output);
	_mutex.lock();
	pView->Print("Output of NAND:" + std::to_string(output));
	_mutex.unlock();
	//CallNext();
	return 1;
}

Component* NAND::Clone()
{
	return new NAND();
}
