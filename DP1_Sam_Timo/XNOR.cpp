#include "XNOR.h"

void XNOR::ExecuteOperation() {
	//TODO: remove
	_value1 = 1;
	_value2 = 0;

	int output = _value1==_value2;

	pView->Print(output);
	CallNext();
}
