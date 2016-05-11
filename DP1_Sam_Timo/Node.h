#ifndef _NODE_H
#define _NODE_H

#include "Component.h"

class Node : public Component 
{
protected:
	std::string Identifier;
public:
	Node();
	~Node();

	virtual void ExecuteOperation() = 0;
	void WaitForValues();
};

#endif _NODE_H