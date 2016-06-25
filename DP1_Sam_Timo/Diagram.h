#ifndef _DIAGRAM_H
#define _DIAGRAM_H

#include <fstream>
#include <string>
#include <windows.h>
#include <map>
#include <vector>
#include <algorithm>

#include "Component.h"
#include "Circuit.h"

class Diagram
{
private:
	std::map<std::string, std::vector<std::string>> callers;
	std::map<std::string, std::vector<std::string>> calling;
public:
	Diagram();
	~Diagram();

	void Create(Circuit& circuit);
	void GetNext(Component& component, std::vector<Component*>* components);
};

#endif
