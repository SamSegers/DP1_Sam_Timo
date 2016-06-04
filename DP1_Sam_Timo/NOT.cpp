#include "NOT.h"

int NOT::ExecuteOperation() {
	int output = !values.at(0);
	values.clear();
	values.push_back(output);
	_mutex.lock();
	pView->Print("Output of NOT:" + std::to_string(output));
	_mutex.unlock();
	//CallNext();

	return 1;
}

Component* NOT::Clone()
{
	return new NOT();
}