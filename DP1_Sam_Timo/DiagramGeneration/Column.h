#pragma once

#include <vector>

#include "../Composite/Composite.h"
#include "EdgePopulation.h"

namespace DiagramGeneration
{
	struct Column
	{
		std::vector<Composite*> components;
		unsigned x;
		unsigned height;
		unsigned edgeX;
		std::vector<EdgePopulation> edgeYPopulations;
	};
}

