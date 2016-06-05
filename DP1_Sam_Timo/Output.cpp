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
		script += "\
			components[" + std::to_string(i) + "] = {\
				id: '" + components[i]->GetId() + "',\
				callers: [\
		";

		std::vector<std::string>& calls = callers[components[i]->GetId()];

		for (int j = 0; j < calls.size(); j++) script += "'" + calls[j] + "', ";

		script += "]\
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
			std::vector<std::string>& calls = callers[next[i]->GetId()];
			if (std::find(calls.begin(), calls.end(), component.GetId()) == calls.end()) {
				callers[next[i]->GetId()].push_back(component.GetId());
			}
			DiagramGetNext(*next[i], components);
		}
	}
}