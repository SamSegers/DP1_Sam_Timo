#pragma once
#ifndef _JS_GENERATOR_H
#define _JS_GENERATOR_H

#include <fstream>
#include <string>
#include <windows.h>
#include <map>
#include <vector>
#include <algorithm>

#include "..\Composite\Composite.h"
#include "..\Circuit.h"
#include "Generator.h"

namespace DiagramGeneration
{
	// roept naar js en maakt dan het diagram.
	class JsGenerator : public Generator
	{
	private:
		const std::string INPUT_FILE = "DiagramVisualisation\\projects\\js_based\\input\\init.js";
		const char* HTML_FILE = "DiagramVisualisation\\projects\\js_based\\index.html";

		std::string script;

		std::map<std::string, std::vector<std::string>> callers;
		std::map<std::string, std::vector<std::string>> calling;

		void GetNext(Composite& component, std::vector<Composite*>* components);
	public:
		void GenerateData(Circuit& circuit) override;
		void WriteInputs() override;
		void Show() override;
	};
}

#endif
