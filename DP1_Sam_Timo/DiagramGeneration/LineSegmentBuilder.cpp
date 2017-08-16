#include "LineSegmentBuilder.h"

namespace DiagramGeneration
{
	void LineSegmentBuilder::SetBegin(Vector vector)
	{
		lineSegment.begin = vector;	
	}

	void LineSegmentBuilder::SetBeginX(int x)
	{
		lineSegment.begin.x = x;	
	}

	void LineSegmentBuilder::SetBeginY(int y)
	{
		lineSegment.begin.y = y;	
	}

	void LineSegmentBuilder::SetEnd(Vector vector)
	{
		lineSegment.end = vector;	
	}

	void LineSegmentBuilder::SetEndX(int x)
	{
		lineSegment.end.x = x;	
	}

	void LineSegmentBuilder::SetEndY(int y)
	{
		lineSegment.end.y = y;	
	}

	void LineSegmentBuilder::SetColorBlack()
	{
		lineSegment.color = BLACK;
	}

	void LineSegmentBuilder::SetColorBlue()
	{
		lineSegment.color = BLUE;
	}

	LineSegment LineSegmentBuilder::GetResult()
	{
		return lineSegment;	
	}
}