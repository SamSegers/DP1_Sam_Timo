#include "NOT.h"

void NOT::ExecuteOperation() {
	int output = !_value1;

	pView->Print(output);
	CallNext();
}

Component* NOT::Clone()
{
	return new NOT();
}