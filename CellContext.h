#pragma once

class Operation;
class Cell;
#include "Value.h"
#include "CellType.h"

struct CellContext 
{
	CellContext() = default;
	CellContext(const CellType& cellType);
	CellContext(const Value& value);
	CellContext(Operation* op);
	CellContext(Cell* reference);

	CellType type = CellType::Empty;

	Value value; //For SingleValueCell
	Operation* operation = nullptr; //For FormulaCell
	Cell* reference = nullptr; //For ReferencCell
	bool isEmpty = true;
};