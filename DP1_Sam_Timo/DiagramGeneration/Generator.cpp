#include "Generator.h"

namespace DiagramGeneration
{
	// template method pattern
	void Generator::Generate(Circuit& circuit)
	{
		GenerateData(circuit);
		WriteInputs();
		Show();
		Clear();
	}
}
