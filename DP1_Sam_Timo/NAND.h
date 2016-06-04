#ifndef _NAND_H
#define _NAND_H

#include "Node.h"

class NAND : public Node
{
public:
	int ExecuteOperation();
	virtual Component* Clone();
};

#endif _XAND_H