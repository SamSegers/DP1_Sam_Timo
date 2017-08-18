#ifndef _CIRCUIT_H
#define _CIRCUIT_H

#include <memory>
#include <vector>

#include "Factory.h"
#include "Probe.h"
#include "Input.h"
#include "Composite\Edge.h"
#include "Composite\Component.h"
#include "Output.h"

// Stelt de data uit een file voor.
class Circuit
{
private:
	bool _inputsSet;
	bool _isSuccesful;

	int _high;
	int _low;
protected:
	std::shared_ptr<Output> pView;
	std::vector<Node *> Nodes;
	std::vector<Probe *> Probes;
	std::vector<Input *> Inputs;
	std::vector<Edge *> Edges;

	std::shared_ptr<Visitor> pVisitor;

	int Link(std::string Data, Edge *);
	int LinkAdd(std::vector<Composite *>, Edge *pEdge, std::string id, bool toEdge);
	void CheckIfCircuitWasSuccessful();
	int ErrorFound(std::string error);
public:
	Circuit();
	~Circuit();

	int CreateNodes(std::vector<std::string>);
	int CreateEdges(std::vector<std::string>);
	int CreateProbes(std::vector<std::string>);
	int CreateInputs(std::vector<std::string>);
	std::vector<Input*> GetInputs();

	void SetInputs(int high, int low);
	void SetOutput(std::shared_ptr<Output> pOutput);
	void SetVisitor(std::shared_ptr<Visitor> pVisitor);

	std::vector<Probe *> Start();

	bool IsSuccesful();
};

#endif _CIRCUIT_H