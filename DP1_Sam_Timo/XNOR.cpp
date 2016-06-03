#include "XNOR.h"

void XNOR::ExecuteOperation() {
	int output = _value1==_value2;

	pView->Print(output);
	CallNext();
}

Component* XNOR::Clone()
{
	return new XNOR();
}