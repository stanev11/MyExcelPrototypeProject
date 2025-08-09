#include "CellContext.h"

CellContext::CellContext(const Value& value) : value(value)
{
}

CellContext::CellContext(Operation* op)
{
	if (op == nullptr)
	{
		throw std::invalid_argument("Nullptr!");
	}

	operation = op;
}

CellContext::CellContext(Cell* reference)
{
	if (reference == nullptr)
	{
		throw std::invalid_argument("Nullptr!");
	}

	this->reference = reference;
}
