#include "JsGenerator.h"

namespace DiagramGeneration
{
	void JsGenerator::GenerateData(Circuit& circuit) 
	{
		try{
			// 1. initialisation
			std::vector<Composite*> components;
			std::vector<Input*> inputs = circuit.GetInputs();

			script = R"(
				'use strict';
				let components = [];
			)";

			// 2. get components
			// loop through inputs
			for(int i=0; i<inputs.size(); i++) 
				GetNext(*inputs[i], &components);

			// transforming string vector to array data const char* for use in js
			auto arrayData = [](std::vector<std::string> elements) -> std::string 
			{
				std::string data;
				for(const auto& element : elements)
					data += "'" + element + "', ";
				return data;
			};

			// 3. print script
			for (int i = 0; i < components.size(); i++) {
				auto* pComponent = components[i];
				const auto id = pComponent->GetId();

				std::vector<std::string>& next = calling[id];
				std::vector<std::string>& previous = callers[id];

				const char* name = *pComponent;
				const auto value = std::to_string(pComponent->GetValues().size() > 0 ? pComponent->GetValues()[0] : 0);

				const auto previousData = arrayData(previous);
				const auto nextData = arrayData(next);

				script += 
					"components['" + std::to_string(i) + "'] = { \
						id: '" + id + "',\
						gate: '" + name + "',\
						value: '" + value + "',\
						previous: [ " + previousData + "],\
						next: [ " + nextData + "]\
					};"
				;
			}
		}
		catch(std::exception ex){
			std::cerr << ex.what() << std::endl;	
		}
	}

	// recursively going through components adding them to containers
	void JsGenerator::GetNext(Composite& component, std::vector<Composite*>* components) 
	{
		// prevent duplicates
		if (std::find(components->begin(), components->end(), &component) != components->end())
			return;

		components->push_back(&component);

		if (component.GetNext().size() <= 0)
			return;

		auto next = component.GetNext()[0]->GetNext();
		for (int i = 0; i < next.size(); i++) {
			const auto nextId = next[i]->GetId();
			calling[component.GetId()].push_back(nextId); // add to next array of current component

			std::vector<std::string>& calls = callers[nextId];
			if (std::find(calls.begin(), calls.end(), component.GetId()) == calls.end())
				callers[nextId].push_back(component.GetId()); // add to previous array of next component
			GetNext(*next[i], components);
		}
	}

	void JsGenerator::WriteInputs()
	{
		std::ofstream file(INPUT_FILE);
		file << script;
		file.close();
	}

	// opens the browser
	void JsGenerator::Show()
	{
		ShellExecute(NULL, "open", HTML_FILE, NULL, NULL, SW_SHOWNORMAL);
	}
}