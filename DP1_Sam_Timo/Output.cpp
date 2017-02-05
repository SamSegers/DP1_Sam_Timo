#include "Output.h"

// vraag voor een high value.
int Output::AskForInputHigh()
{
	std::cout << "Give a value for high: ";

	int out = 1;
	std::cin >> out;
	return out;
}
// vraag voor een low value.
int Output::AskForInputLow()
{
	std::cout << "Give a value for low: ";
	int out = 0;
	std::cin >> out;
	return out;
}
// vraag of er opnieuw gerunt moet worden.
std::string Output::RunAgain()
{
	std::string val = "";
	std::cin >> val;
	return val;
}

// print waardes
void Output::Print(int& value) {
	std::cout << "output = " << value << std::endl;
}

void Output::Print(std::string value) {
	std::cout << "output = " << value << std::endl;
}
