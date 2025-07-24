#pragma once

#include "Value.h"
#include "Cell.h"

//#include "FormulaName.h"=

#include "Operation.h" //

class FormulaCell : public Cell
{
private:
	Operation* operation;

	mutable bool evaluated = false;
	mutable Value cachedResult;

public:
	FormulaCell(Operation* op);
	Cell* clone() const override;

	const Value& getValue() const override;
	MyString toString() const override;
};

