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
	const std::string INPUT_FILE = "diagram_visualisation\\projects\\js_based\\input\\init.js";
	const char* HTML_FILE = "diagram_visualisation\\projects\\js_based\\index.html";

	std::string script;

	std::map<std::string, std::vector<std::string>> callers;
	std::map<std::string, std::vector<std::string>> calling;

	void GetNext(Composite& component, std::vector<Composite*>* components);
public:
	void GenerateData(Circuit& circuit) override;
	void WriteInputs() override;
	void Show() override;
};

#endif
