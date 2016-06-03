#ifndef _AND_H
#define _AND_H

#include "Node.h"

class AND : public Node
{
public:
	void ExecuteOperation();
	virtual Component* Clone();
};

#endif _AND_H