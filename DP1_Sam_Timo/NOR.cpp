#include "NOR.h"

void NOR::ExecuteOperation() {

	int output = _value1==0 && _value2==0;
	pView->Print(output);
	CallNext();
}

Component* NOR::Clone()
{
	return new NOR();
}