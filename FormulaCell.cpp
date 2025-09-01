#include "FormulaCell.h"

FormulaCell::FormulaCell(Operation* op) : operation(op) , Cell(CellType::FormulaCell)
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

std::ofstream& FormulaCell::saveToBinaryFile(std::ofstream& ofs) const
{
	Cell::saveToBinaryFile(ofs);

	operation->saveToBinaryFile(ofs);

	/*ofs.write((const char*)&evaluated, sizeof(evaluated));

	if (evaluated)
	{
		cachedResult.saveToBinaryFile(ofs);
	}*/

	return ofs;
}
