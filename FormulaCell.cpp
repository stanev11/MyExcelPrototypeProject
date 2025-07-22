#include "FormulaCell.h"

FormulaCell::FormulaCell(Operation* op) : operation(op)
{
}

Cell* FormulaCell::clone() const
{
	return new FormulaCell(*this);
}
