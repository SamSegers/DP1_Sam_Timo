#include "Node.h"

Node::Node(){}
Node::~Node(){}

void Node::CallNext() {
	for (int i = 0; i < sizeof(pEdges) / sizeof(pEdges[0]); i++) {
		if (pEdges[i] != NULL) {
			//TODO give value to edges
		}
	}
}

void Node::WaitForValues() {

}