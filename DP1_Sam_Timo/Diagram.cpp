#include "Diagram.h"

Diagram::Diagram()
{

}

Diagram::~Diagram()
{

}

void Diagram::Create(Circuit& circuit) {
	// 1. initialisation
	std::vector<Composite*> components;
	std::vector<Input*> inputs = circuit.GetInputs();

	std::string script = "\
		'use strict';\
		let components = [];\
	";

	// 2. get components
	// loop through inputs
	for(int i=0; i<inputs.size(); i++) GetNext(*inputs[i], &components);

	// 3. print script
	for (int i = 0; i < components.size(); i++) {
		Component& component = *components[i];

		std::vector<std::string>& next = calling[components[i]->GetId()];
		std::vector<std::string>& previous = callers[components[i]->GetId()];

		std::string gate = 
			dynamic_cast<AND*>(&component) != NULL ? "AND" :
			dynamic_cast<NAND*>(&component) != NULL ? "NAND" :
			dynamic_cast<NOR*>(&component) != NULL ? "NOR" :
			dynamic_cast<NOT*>(&component) != NULL ? "NOT" :
			dynamic_cast<OR*>(&component) != NULL ? "OR" :
			dynamic_cast<XNOR*>(&component) != NULL ? "XNOR" :
			dynamic_cast<XOR*>(&component) != NULL ? "XOR" : "";

		script += "\
			components['" + std::to_string(i) + "'] = {\
				id: '" + component.GetId() + "',\
				gate: '" + gate + "',\
				value: '" + std::to_string(component.GetValues()[0]) + "',\
				previous: [\
		";

		for (int j = 0; j < previous.size(); j++) script += "'" + previous[j] + "', ";

		script += "\
				],\
				next: [";

		for (int j = 0; j < next.size(); j++) script += "'" + next[j] + "', ";

		script += "\
				]\
			};\
		";
	}

	std::ofstream file("diagram\\js\\init.js");
	file << script;

	// 4. execute
	ShellExecute(NULL, "open", "diagram\\index.html", NULL, NULL, SW_SHOWNORMAL);
}

void Diagram::GetNext(Composite& component, std::vector<Composite*>* components) {
	if (std::find(components->begin(), components->end(), &component) == components->end()){
		components->push_back(&component);
		
		if (component.GetNext().size() > 0) {
			std::vector<Composite*> next = component.GetNext()[0]->GetNext();

			for (int i = 0; i < next.size(); i++) {
				calling[component.GetId()].push_back(next[i]->GetId()); // add to next array of current component

				std::vector<std::string>& calls = callers[next[i]->GetId()];
				if (std::find(calls.begin(), calls.end(), component.GetId()) == calls.end()) {
					callers[next[i]->GetId()].push_back(component.GetId()); // add to previous array of next component
				}
				GetNext(*next[i], components);
			}
		}
	}
}
