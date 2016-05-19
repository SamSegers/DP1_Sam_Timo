#include "OR.h"

void OR::ExecuteOperation() {
	//TODO remove
	_value1 = 0;
	_value2 = 1;

	int output = _value1 || _value2;

	pView->Print(output);
	CallNext();
}
