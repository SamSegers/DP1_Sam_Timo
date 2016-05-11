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