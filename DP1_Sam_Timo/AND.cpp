#include "AND.h"

void AND::ExecuteOperation() {
	int output = _value1==_value2;

	pView->Print(output);
	CallNext();
}

Component* AND::Clone()
{
	return new AND();
}