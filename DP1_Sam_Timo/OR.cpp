#include "OR.h"

void OR::ExecuteOperation() {

	int output = _value1 || _value2;

	pView->Print(output);
	CallNext();
}

Component* OR::Clone()
{
	return new OR();
}