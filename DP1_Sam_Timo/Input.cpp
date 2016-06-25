#include "Input.h"



Component* Input::Clone()
{
	return new Input();
}

void Input::InputHigh()
{
	int input = 1;
	std::cin >> input;

	this->InsertValue(input);
}

void Input::InputLow()
{
	int input = 0;
	std::cin >> input;

	this->InsertValue(input);
}