#include "Input.h"

const char* Input::NAME = "Input";

// clone een nieuwe input
Component* Input::Clone()
{
	return new Input();
}