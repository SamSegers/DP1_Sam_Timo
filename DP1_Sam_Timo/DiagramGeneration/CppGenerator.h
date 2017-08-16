#pragma once
#ifndef _CPP_DIAGRAM_GENERATOR_H
#define _CPP_DIAGRAM_GENERATOR_H

#include <fstream>
#include <map>
#include <sstream>
#include <windows.h>

#include "Column.h"
#include "Generator.h"
#include "LineSegment.h"
#include "LineSegmentBuilder.h"
#include "SvgElement.h"
#include "VisualNode.h"

namespace DiagramGeneration
{
	// maakt het diagram en roept dan js aan op het te visualiseren.
	class CppGenerator : public Generator
	{
		const std::string styleFile = "DiagramVisualisation\\projects\\svg_based\\style.css";
		const std::string htmlFile = "DiagramVisualisation\\projects\\svg_based\\index.html";
		const unsigned int SPACE = 20; // spacing between edges and between nodes
		const unsigned int NODE_SIZE = 80;
		const unsigned int HEIGHT_LIMIT = SPACE * 1000; // defines a limit to prevent infinite loops

		std::string htmlFileDataBegin;
		std::string htmlFileDataEnd;
		SvgElement svg;
		std::vector<Column> columns;
		LineSegmentBuilder lineSegmentBuilder;
		std::vector<LineSegment> lineSegments;
		std::map<Composite*, VisualNode> visualNodes;

		void InitFileTemplate();

		void CreateColumns(Circuit& circuit);
		void InitVisualNodes(Circuit& circuit);
		void DeduceColumnPosition(Column& column);

		void CreateEdges();
		unsigned int GetTravelY(unsigned int firstColumnIndex, unsigned int lastColumnIndex);

		void GenerateSvgContent();
		void DeduceSvgSize();

	public:
		CppGenerator();

		void GenerateData(Circuit& circuit) override;
		void WriteInputs() override;
		void Show() override;
	};
}


#endif
