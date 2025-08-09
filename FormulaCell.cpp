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
	if (!evaluated)
	{
		try
		{
			cachedResult = operation->execute();
			evaluated = true;
		}
		catch (const std::exception&)
		{
			cachedResult.setErrorState();
			evaluated = false;
		}
	}
	return cachedResult;
}

MyString FormulaCell::toString() const
{
	return getValue().toString();
}
