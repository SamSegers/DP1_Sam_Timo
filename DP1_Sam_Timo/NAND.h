#ifndef _NAND_H
#define _NAND_H

#include "Node.h"
// voert de NAND functionaliteit uit
class NAND : public Node
{
public:
	int ExecuteOperation();
	virtual Component* Clone();
	operator const char*() const override { return "NAND"; };
};

#endif _XAND_H