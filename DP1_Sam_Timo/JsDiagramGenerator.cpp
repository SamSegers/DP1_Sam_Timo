#include "JsDiagramGenerator.h"

void JsDiagramGenerator::GenerateData(Circuit& circuit) {
	try{
		// 1. initialisation
		std::vector<Composite*> components;
		std::vector<Input*> inputs = circuit.GetInputs();

		script = "\
			'use strict';\
			let components = [];\
		";

		// 2. get components
		// loop through inputs
		for(int i=0; i<inputs.size(); i++) 
			GetNext(*inputs[i], &components);

		// 3. print script
		for (int i = 0; i < components.size(); i++) {
			Component& component = *components[i];

			std::vector<std::string>& next = calling[components[i]->GetId()];
			std::vector<std::string>& previous = callers[components[i]->GetId()];

			std::string gate = 
				dynamic_cast<AND*>(&component) != nullptr ? "AND" :
				dynamic_cast<NAND*>(&component) != nullptr ? "NAND" :
				dynamic_cast<NOR*>(&component) != nullptr ? "NOR" :
				dynamic_cast<NOT*>(&component) != nullptr ? "NOT" :
				dynamic_cast<OR*>(&component) != nullptr ? "OR" :
				dynamic_cast<XNOR*>(&component) != nullptr ? "XNOR" :
				dynamic_cast<XOR*>(&component) != nullptr ? "XOR" : "";

			std::string value = component.GetValues().size() > 0 ? std::to_string(component.GetValues()[0]) : "0";

			script += "\
				components['" + std::to_string(i) + "'] = {\
					id: '" + component.GetId() + "',\
					gate: '" + gate + "',\
					value: '" + value + "',\
					previous: [\
			";

			for (int j = 0; j < previous.size(); j++) 
				script += "'" + previous[j] + "', ";

			script += "\
					],\
					next: [";

			for (int j = 0; j < next.size(); j++) 
				script += "'" + next[j] + "', ";

			script += "\
					]\
				};\
			";
		}
	}
	catch(std::exception ex){
		std::cerr << ex.what() << std::endl;	
	}
}

void JsDiagramGenerator::WriteInputs()
{
	std::ofstream file(INPUT_FILE);
	file << script;
}

// opens the browser
void JsDiagramGenerator::Show()
{
	ShellExecute(NULL, "open", HTML_FILE, NULL, NULL, SW_SHOWNORMAL);
}

void JsDiagramGenerator::GetNext(Composite& component, std::vector<Composite*>* components) {
	if (std::find(components->begin(), components->end(), &component) == components->end()){
		components->push_back(&component);
		
		if (component.GetNext().size() > 0) {
			std::vector<Composite*> next = component.GetNext()[0]->GetNext();

			for (int i = 0; i < next.size(); i++) {
				calling[component.GetId()].push_back(next[i]->GetId()); // add to next array of current component

				std::vector<std::string>& calls = callers[next[i]->GetId()];
				if (std::find(calls.begin(), calls.end(), component.GetId()) == calls.end())
					callers[next[i]->GetId()].push_back(component.GetId()); // add to previous array of next component
				GetNext(*next[i], components);
			}
		}
	}
}
