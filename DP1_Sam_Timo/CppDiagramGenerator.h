#pragma once
#ifndef _CPP_DIAGRAM_GENERATOR_H
#define _CPP_DIAGRAM_GENERATOR_H

#include "DiagramGenerator.h"

// maakt het diagram en roept dan js aan op het te visualiseren.
class JsDiagramGenerator : public DiagramGenerator
{
public:
	void Generate(Circuit& circuit) override
	{}
};

#endif
