#pragma once
#ifndef _DIAGRAM_GENERATOR_H
#define _DIAGRAM_GENERATOR_H

#include "circuit.h"

class DiagramGenerator 
{
public:
	void Generate(Circuit& circuit);

protected:
	virtual void GenerateData(Circuit& circuit) = 0;
	virtual void WriteInputs() = 0;
	virtual void Show() = 0;
};

#endif
