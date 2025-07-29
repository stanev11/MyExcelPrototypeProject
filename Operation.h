#pragma once

#include "IParameter.h"
#include "Value.h"

class Operation
{
public:
	virtual Operation* clone() const = 0;
	virtual ~Operation() = default;

	virtual Value execute() = 0;

	//virtual void undo();
	//virtual void redo();
};

