#include "NOR.h"

int NOR::ExecuteOperation() {

	if (this->values.size() < 2)
		return 0;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration> start = std::chrono::high_resolution_clock::now();
	int output = values.at(0) == 0 && values.at(1) == 0;
	std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration> finish = std::chrono::high_resolution_clock::now();
	values.clear();
	values.push_back(output);
	_mutex.lock();
	pView->Print("Operation took: " + std::to_string(std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count()) + "ns.");
	pView->Print("Output of NOR:" + std::to_string(output));
	_mutex.unlock();
	//CallNext();

	return 1;
}

Component* NOR::Clone()
{
	return new NOR();
}