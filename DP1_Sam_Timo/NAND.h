#ifndef _NAND_H
#define _NAND_H

#include "Node.h"

class NAND : public Node
{
public:
	void ExecuteOperation();
	virtual Component* Clone();
};

#endif _XAND_H