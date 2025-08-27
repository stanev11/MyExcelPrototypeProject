#pragma once

class Cell;

#include "IParameter.h"
#include "Value.h"
#include "FormulaType.h"
#include "fstream"

class Operation
{
protected:
	FormulaType formulaType;

public:
	Operation(const FormulaType& formulaType);

	virtual Operation* clone() const = 0;
	virtual ~Operation() = default;

	virtual Value execute() = 0;

	virtual bool hasCircularReference(const Cell& cell) const = 0;

	//virtual void undo() = 0;

	//virtual void redo();

	FormulaType getFormulaType() const;

	virtual std::ofstream& saveToBinaryFile(std::ofstream& ofs) const;
};

