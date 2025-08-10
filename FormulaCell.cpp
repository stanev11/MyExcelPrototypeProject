#include "FormulaCell.h"

FormulaCell::FormulaCell(Operation* op) : operation(op)
{
}

Cell* FormulaCell::clone() const
{
	return new FormulaCell(*this);
}

const Value& FormulaCell::getValue() const
{
	if (operation->hasCircularReference(*this))
	{
		cachedResult.setErrorState();
	}

	else if (!evaluated)
	{
		cachedResult = operation->execute();
		evaluated = true;
	}
	return cachedResult;
}

MyString FormulaCell::toString() const
{
	return getValue().toString();
}
