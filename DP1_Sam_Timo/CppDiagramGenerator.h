#pragma once
#ifndef _CPP_DIAGRAM_GENERATOR_H
#define _CPP_DIAGRAM_GENERATOR_H

#include "DiagramGenerator.h"

// TODO implementation

// maakt het diagram en roept dan js aan op het te visualiseren.
class CppDiagramGenerator : public DiagramGenerator
{
public:
	void GenerateData(Circuit& circuit) override;
	void WriteInputs() override;
	void Show() override;
};

#endif
