#include "XOR.h"
// voer xor uit.
int XOR::ExecuteOperation() {
	// kijk of de waardes aanwezig zijn.
	if (this->values.size() < 2)
		return 0;
	int output = values.at(0)!=values.at(1);
	// zet alles klaar om door te geven.
	values.clear();
	values.push_back(output);
	//DoThis();
	return 1;
}
// clone xor.
Component* XOR::Clone()
{
	return new XOR();
}