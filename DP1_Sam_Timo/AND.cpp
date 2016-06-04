#include "AND.h"

int AND::ExecuteOperation() {

	if (this->values.size() < 2)
		return 0;

	int output = values.at(0) == values.at(1);

	values.clear();
	values.push_back(output);
	_mutex.lock();
	pView->Print("Output of AND:" + std::to_string(output));
	_mutex.unlock();
	//CallNext();

	return 1;
}

Component* AND::Clone()
{
	return new AND();
}