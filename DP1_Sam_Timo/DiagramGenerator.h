#pragma once
#ifndef _DIAGRAM_GENERATOR_H
#define _DIAGRAM_GENERATOR_H

#include "circuit.h"

class DiagramGenerator 
{
public:
	virtual void Generate(Circuit& circuit) = 0;
};

#endif
