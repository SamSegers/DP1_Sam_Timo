#pragma once
#ifndef _CPP_DIAGRAM_GENERATOR_H
#define _CPP_DIAGRAM_GENERATOR_H

#include <windows.h>
#include <fstream>
#include <sstream>

#include "DiagramGenerator.h"

struct Vector
{
	int x;
	int y;
};

struct LineSegment
{
	Vector begin;
	Vector end;
	std::string color;
};

struct VisualEdge
{
	std::vector<LineSegment> lineSegments;
};

struct EdgePopulation
{
	int top;
	int bottom;
};

struct Column
{
	std::vector<Composite*> components;
	unsigned int x;
	unsigned int y;
};

struct Svg
{
	std::string content;
	unsigned int width;
	unsigned int height;
};

// maakt het diagram en roept dan js aan op het te visualiseren.
class CppDiagramGenerator : public DiagramGenerator
{
	const char* HTML_FILE = "diagram_visualisation\\projects\\svg_based\\index.html";
	const char* HTML_FILE_DATA_BEGIN = R"(
<!DOCTYPE HTML>

<html>
    <head>
        <meta name="generator" content="Microsoft Visual Studio">
        <title>Diagram</title>
        <link href='../../styles/legend.css' rel='stylesheet'>
        <script src="main.js" async></script>
		<style>
			rect.gate
			{
				fill: #fff;
				stroke: #000;
			}
		</style>
    </head>
    <body>
        <section class="nodes">
            <div>
                <img src="../../img/AND.png"/>
                <span class="name">AND</span>
            </div>
            <div>
                <img src="../../img/NAND.png"/>
                <span class="name">NAND</span>
            </div>
            <div>
                <img src="../../img/NOR.png"/>
                <span class="name">NOR</span>
            </div>
            <div>
                <img src="../../img/NOT.png"/>
                <span class="name">NOT</span>
            </div>
            <div>
                <img src="../../img/OR.png"/>
                <span class="name">OR</span>
            </div>
            <div>
                <img src="../../img/XNOR.png"/>
                <span class="name">XNOR</span>
            </div>
            <div>
                <img src="../../img/XOR.png"/>
                <span class="name">XOR</span>
            </div>
        </section>)"
	;
	const char* HTML_FILE_DATA_END = R"(
    </body>
</html>)"
	;
	const unsigned int SPACE = 20; // spacing between edges and between nodes
	const unsigned int COMPONENT_SIZE = 80;
	const unsigned int HEIGHT_LIMIT = SPACE * 1000; // defines a limit to prevent infinite loops

	Svg svg;
	std::vector<Column> columns;
	std::vector<VisualEdge> edges;

	void CreateColumns(Circuit& circuit);
	void DeduceColumnPosition(Column& column);

	void CreateEdges();

public:
	void GenerateData(Circuit& circuit) override;
	void WriteInputs() override;
	void Show() override;
};

#endif
