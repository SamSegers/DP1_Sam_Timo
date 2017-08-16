#pragma once

#include <string>

#include "vector.h"

namespace DiagramGeneration
{
	struct LineSegment
	{
		Vector begin;
		Vector end;
		std::string color = "#000";
	};
}
