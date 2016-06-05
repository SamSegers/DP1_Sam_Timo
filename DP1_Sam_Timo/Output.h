#ifndef _OUTPUT_H
#define _OUTPUT_H

#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <map>
#include <vector>
#include <algorithm>

#include "Component.h"

class Component;
class Circuit;
class Output
{
private:
	std::map<std::string, std::vector<std::string>> callers;
public:
	Output();
	~Output();

	void Print(int& value);
	void Print(std::string value);
	void CreateDiagram(Circuit& circuit);
	void DiagramGetNext(Component& component, std::vector<Component*>* components);
};

#endif