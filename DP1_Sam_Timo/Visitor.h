#ifndef _VISITOR_H
#define _VISITOR_H

#include <memory>
#include <chrono>
#include "Output.h"


// forward declare
class Node;
class Probe;
class Input;
class Edge;
class Component;
class Composite;

// visitor voor uitvoering van nodes en dergelijk.
class Visitor
{
protected:
	std::shared_ptr<Output> pView;
public:
	virtual void Visit(Node* pNode);
	virtual void Visit(Probe* pProbe);
	virtual void Visit(Composite* pComposite);
	virtual void SetOutput(std::shared_ptr<Output> pView);
};

#endif