#ifndef _DIAGRAM_H
#define _DIAGRAM_H

#include <fstream>
#include <string>
#include <windows.h>
#include <map>
#include <vector>
#include <algorithm>

#include "Composite.h"
#include "Circuit.h"

// roept naar js en maakt dan het diagram.
class Diagram
{
private:
	std::map<std::string, std::vector<std::string>> callers;
	std::map<std::string, std::vector<std::string>> calling;
public:
	void Create(Circuit& circuit);
	void GetNext(Composite& component, std::vector<Composite*>* components);
};

#endif
