#pragma once
#ifndef _JS_DIAGRAM_GENERATOR_H
#define _JS_DIAGRAM_GENERATOR_H

#include <fstream>
#include <string>
#include <windows.h>
#include <map>
#include <vector>
#include <algorithm>

#include "Composite.h"
#include "Circuit.h"
#include "DiagramGenerator.h"

// roept naar js en maakt dan het diagram.
class JsDiagramGenerator : public DiagramGenerator
{
private:
	std::map<std::string, std::vector<std::string>> callers;
	std::map<std::string, std::vector<std::string>> calling;

	void GetNext(Composite& component, std::vector<Composite*>* components);
public:
	void Generate(Circuit& circuit) override;
};

#endif
