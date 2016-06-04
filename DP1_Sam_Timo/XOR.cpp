#include "XOR.h"

int XOR::ExecuteOperation() {

	if (this->values.size() < 2)
		return 0;
	int output = values.at(0)!=values.at(1);
	values.clear();
	values.push_back(output);
	_mutex.lock();
	pView->Print("Output of XOR:" + std::to_string(output));
	_mutex.unlock();
	//CallNext();
	return 1;
}

Component* XOR::Clone()
{
	return new XOR();
}