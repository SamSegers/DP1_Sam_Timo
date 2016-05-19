#include "Output.h"

Output::Output()
{

}

Output::~Output()
{

}

void Output::Print(int& value) {
	std::cout << "output = " << value << std::endl;
}

void Output::Print(std::string value) {
	std::cout << "output = " << value << std::endl;
}