#include "Output.h"

Output::Output()
{

}

Output::~Output()
{

}

void Output::AskForValues()
{
	std::cout << "Give INPUT_HIGH value:" << std::endl;
	std::cout << "Give INPUT_LOW value:" << std::endl;
}

void Output::Print(int& value) {
	std::cout << "output = " << value << std::endl;
}

void Output::Print(std::string value) {
	std::cout << "output = " << value << std::endl;
}
