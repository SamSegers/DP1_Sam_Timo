#ifndef _OUTPUT_H
#define _OUTPUT_H

#include <iostream>
#include <string>

class Output
{
public:
	Output();
	~Output();


	int AskForInputHigh();
	int AskForInputLow();
	void Print(int& value);
	void Print(std::string value);
};

#endif