#include "NOR.h"

int NOR::ExecuteOperation() {

	if (this->values.size() < 2)
		return 0;

	int output = values.at(0) == 0 && values.at(1) == 0;
	values.clear();
	values.push_back(output);
	_mutex.lock();
	pView->Print("Output of NOR:" + std::to_string(output));
	_mutex.unlock();
	//CallNext();

	return 1;
}

Component* NOR::Clone()
{
	return new NOR();
}