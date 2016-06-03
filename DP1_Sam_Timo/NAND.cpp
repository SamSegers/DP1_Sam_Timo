#include "NAND.h"

void NAND::ExecuteOperation() {
	//TODO remove
	_value1 = 1;
	_value2 = 0;

	int output = _value1!=1 || _value2!=1;

	pView->Print(output);
	CallNext();
}

Component* NAND::Clone()
{
	return new NAND();
}
