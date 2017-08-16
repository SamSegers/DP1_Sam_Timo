#pragma once

#include <string>

namespace DiagramGeneration
{
	struct SvgElement
	{
		std::string content;
		unsigned int width = 0;
		unsigned int height = 0;
	};
}