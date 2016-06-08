#include "NOT.h"

int NOT::ExecuteOperation() {
	std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration> start = std::chrono::high_resolution_clock::now();
	int output = !values.at(0);
	std::chrono::time_point<std::chrono::system_clock, std::chrono::system_clock::duration> finish = std::chrono::high_resolution_clock::now();
	values.clear();
	values.push_back(output);
	_mutex.lock();
	pView->Print("Operation took: " + std::to_string(std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count()) + "ns.");
	pView->Print("Output of NOT:" + std::to_string(output));
	_mutex.unlock();
	//CallNext();

	return 1;
}

Component* NOT::Clone()
{
	return new NOT();
}