#ifndef _CIRCUIT_H
#define _CIRCUIT_H

#include <vector>
#include "Factory.h"
#include "Probe.h"
#include "Input.h"
#include "Edge.h"
#include "Component.h"
#include "Output.h"

class Circuit
{
protected:
	Output *pView;
	std::vector<Node *> Nodes;
	std::vector<Probe *> Probes;
	std::vector<Input *> Inputs;
	std::vector<Edge *> Edges;

	Visitor *pVisitor;

	int Link(std::string Data, Edge *);
	int LinkAdd(std::vector<Composite *>, Edge *pEdge, std::string id, bool toEdge);
	void CheckIfCircuitWasSuccesful();
	int ErrorFound(std::string error);
public:
	Circuit();
	~Circuit();

	int CreateNodes(std::vector<std::string>);
	int CreateEdges(std::vector<std::string>);
	int CreateProbes(std::vector<std::string>);
	int CreateInputs(std::vector<std::string>);
	int CheckForLinkErrors();
	std::vector<Input*> GetInputs();

	void SetOutput(Output *output);
	void SetVisitor(Visitor *pVisitor);

	void Start();

};

#endif _CIRCUIT_H