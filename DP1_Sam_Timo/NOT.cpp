#include "NOT.h"

void NOT::ExecuteOperation() {
	//TODO: remove
	_value1 = 1;

	int output = !_value1;

	pView->Print(output);
	CallNext();
}
