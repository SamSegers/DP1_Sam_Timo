#include "XOR.h"

void XOR::ExecuteOperation() {
	int output = _value1!=_value2;

	pView->Print(output);
	CallNext();
}

Component* XOR::Clone()
{
	return new XOR();
}