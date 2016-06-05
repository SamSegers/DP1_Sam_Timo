#include "Output.h"
#include "Circuit.h"

Output::Output()
{

}

Output::~Output()
{

}

void Output::Print(int& value) {
	std::cout << "output = " << value << std::endl;
}

void Output::Print(std::string value) {
	std::cout << "output = " << value << std::endl;
}

//TODO Diagram class
void Output::CreateDiagram(Circuit& circuit) {
	// 1. initialisation
	std::vector<Component*> components;
	std::vector<Input*> inputs = circuit.GetInputs();

	std::string script = "\
		'use strict';\
		let components = [];\
	";

	//components.push_back(std::vector<Component*>());

	// 2. get components
	// loop through inputs
	for(int i=0; i<inputs.size(); i++) {
		std::cout << "INPUT " << inputs[i]->GetId() << std::endl;
		DiagramGetNext(*inputs[i], &components);
	}

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
			components[" + std::to_string(i) + "] = {\
				id: '" + component.GetId() + "',\
				gate: '" + gate + "',\
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

	std::ofstream file("diagram\\init.js");
	file << script;

	// 4. execute
	ShellExecute(NULL, "open", "diagram\\index.html", NULL, NULL, SW_SHOWNORMAL);
}

void Output::DiagramGetNext(Component& component, std::vector<Component*>* components) {
	if (std::find(components->begin(), components->end(), &component) == components->end() && component.GetNext().size() > 0) {
		components->push_back(&component);
		std::vector<Component*> next = component.GetNext()[0]->GetNext();
		for (int i = 0; i < next.size(); i++) {
			calling[component.GetId()].push_back(next[i]->GetId());

			std::vector<std::string>& calls = callers[next[i]->GetId()];
			if (std::find(calls.begin(), calls.end(), component.GetId()) == calls.end()) {
				callers[next[i]->GetId()].push_back(component.GetId());
			}
			DiagramGetNext(*next[i], components);
		}
	}
}