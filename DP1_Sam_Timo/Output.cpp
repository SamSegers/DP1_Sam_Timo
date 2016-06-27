#include "Output.h"

Output::Output()
{

}

Output::~Output()
{

}

int Output::AskForInputHigh()
{
	std::cout << "Give a value for high: ";

	int out = 1;
	std::cin >> out;
	return out;
}

int Output::AskForInputLow()
{
	std::cout << "Give a value for low: ";
	int out = 0;
	std::cin >> out;
	return out;
}

void Output::Print(int& value) {
	std::cout << "output = " << value << std::endl;
}

void Output::Print(std::string value) {
	std::cout << "output = " << value << std::endl;
}
