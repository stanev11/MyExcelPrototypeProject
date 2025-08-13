#include "CellContext.h"

CellContext::CellContext(const CellType& cellType) : type(cellType)
{
}

CellContext::CellContext(const Value& value) : type(CellType::SingleValueCell), value(value)
{
}

CellContext::CellContext(Operation* op) : type(CellType::FormulaCell)
{
	if (op == nullptr)
	{
		throw std::invalid_argument("Nullptr!");
	}

	operation = op;
}

CellContext::CellContext(Cell* reference) : type(CellType::ReferenceCell)
{
	if (reference == nullptr)
	{
		throw std::invalid_argument("Nullptr!");
	}

	this->reference = reference;
}
