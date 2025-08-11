#pragma once

class Cell;

#include "IParameter.h"
#include "Value.h"

class Operation
{
public:
	virtual Operation* clone() const = 0;
	virtual ~Operation() = default;

	virtual Value execute() = 0;

	virtual bool hasCircularReference(const Cell& cell) const = 0;

	//virtual void undo() = 0;

	//virtual void redo();
};

