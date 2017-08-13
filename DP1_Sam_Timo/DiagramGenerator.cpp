#include "DiagramGenerator.h"

// template method pattern
void DiagramGenerator::Generate(Circuit& circuit)
{
	GenerateData(circuit);
	WriteInputs();
	Show();
}
