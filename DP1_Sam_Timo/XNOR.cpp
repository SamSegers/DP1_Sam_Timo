#include "XNOR.h"
// voer xnor uit.
int XNOR::ExecuteOperation() {
	// kijk of de waardes aanwezig zijn.
	if (this->values.size() < 2)
		return 0;
	int output = values.at(0)==values.at(1);
	// zet alles klaar voor om door te geven.
	values.clear();
	values.push_back(output);

	return 1;
}
// clone xnor.
Component* XNOR::Clone()
{
	return new XNOR();
}