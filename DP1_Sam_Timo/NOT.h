#ifndef _NOT_H
#define _NOT_H

#include "Node.h"

class NOT : public Node
{
public:
	void ExecuteOperation() override;
};

#endif _NOT_H