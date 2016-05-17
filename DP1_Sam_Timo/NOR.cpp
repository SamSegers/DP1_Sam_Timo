#include "NOR.h"

void NOR::ExecuteOperation() {
	//TODO: remove
	_value1 = 1;
	_value2 = 0;

	int output = _value1==0 && _value2==0;

	pView->Print(output);
	CallNext();
}
