#pragma once
#ifndef _CPP_DIAGRAM_GENERATOR_H
#define _CPP_DIAGRAM_GENERATOR_H

#include <fstream>
#include <map>
#include <sstream>
#include <windows.h>

#include "DiagramGenerator.h"

struct Vector
{
	int x;
	int y;
};

struct LineSegment
{
	LineSegment(){}

	LineSegment(Vector begin, Vector end)
	{
		this->begin	= begin;
		this->end = end;
	}

	LineSegment(int x1, int y1, Vector end)
	{
		this->begin.x = x1;
		this->begin.y = y1;
		this->end = end;
	}

	LineSegment(Vector begin, int x2, int y2)
	{
		this->begin	= begin;
		this->end.x = x2;
		this->end.y = y2;
	}

	LineSegment(int x1, int y1, int x2, int y2)
	{
		this->begin.x = x1;
		this->begin.y = y1;
		this->end.x = x2;
		this->end.y = y2;
	}

	Vector begin;
	Vector end;
	std::string color = "#000";
};

struct EdgePopulation
{
	unsigned int top;
	unsigned int bottom;
};

struct VisualNode
{
	Vector position;
	unsigned int columnIndex; // index of the column
	unsigned int index; // index within the column
	std::vector<Composite*> next;
	std::vector<Composite*> previous;
};

struct Column
{
	std::vector<Composite*> components;
	unsigned x;
	unsigned height;
	unsigned edgeX;
	std::vector<EdgePopulation> edgeYPopulations;
};

struct Svg
{
	std::string content;
	unsigned int width = 0;
	unsigned int height = 0;
};

// maakt het diagram en roept dan js aan op het te visualiseren.
class CppDiagramGenerator : public DiagramGenerator
{
	const std::string styleFile = "diagram_visualisation\\projects\\svg_based\\style.css";
	const std::string htmlFile = "diagram_visualisation\\projects\\svg_based\\index.html";
	const unsigned int SPACE = 20; // spacing between edges and between nodes
	const unsigned int NODE_SIZE = 80;
	const unsigned int HEIGHT_LIMIT = SPACE * 1000; // defines a limit to prevent infinite loops

	std::string htmlFileDataBegin;
	std::string htmlFileDataEnd;
	Svg svg;
	std::vector<Column> columns;
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
	CppDiagramGenerator();

	void GenerateData(Circuit& circuit) override;
	void WriteInputs() override;
	void Show() override;
};

#endif
