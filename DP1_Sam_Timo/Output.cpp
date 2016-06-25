#include "Output.h"

Output::Output()
{

}

Output::~Output()
{

}

void Output::AskForInputHigh()
{
	std::cout << "Give a value for high: ";
}

void Output::AskForInputLow()
{
	std::cout << "Give a value for low: ";
}

void Output::Print(int& value) {
	std::cout << "output = " << value << std::endl;
}

void Output::Print(std::string value) {
	std::cout << "output = " << value << std::endl;
}
