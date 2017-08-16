#pragma once

#include <vector>

#include "../Composite/Composite.h"
#include "vector.h"

namespace DiagramGeneration
{
	struct VisualNode
	{
		Vector position;
		unsigned int columnIndex; // index of the column
		unsigned int index; // index within the column
		std::vector<Composite*> next;
		std::vector<Composite*> previous;
	};
}