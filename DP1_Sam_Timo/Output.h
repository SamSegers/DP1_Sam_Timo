#ifndef _OUTPUT_H
#define _OUTPUT_H

#include <iostream>
#include <string>

// print alles naar std::cout
class Output
{
public:
	Output();
	~Output();
	int AskForInputHigh();
	int AskForInputLow();
	std::string RunAgain();
	void Print(int& value);
	void Print(std::string value);
};

#endif