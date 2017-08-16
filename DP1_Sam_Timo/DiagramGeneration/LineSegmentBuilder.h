#pragma once

#include "linesegment.h"
#include "vector.h"

namespace
{
	static const std::string BLACK = "#000";
	static const std::string BLUE = "#00f";
}

namespace DiagramGeneration
{
	class LineSegmentBuilder
	{
	public:
		void SetBegin(Vector vector);
		void SetBeginX(int x);
		void SetBeginY(int y);
		void SetEnd(Vector vector);
		void SetEndX(int x);
		void SetEndY(int y);
		void SetColorBlack();
		void SetColorBlue();

		LineSegment GetResult();
		operator const LineSegment() const { return lineSegment; };
	private:
		LineSegment lineSegment;
	};
}
