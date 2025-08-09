#pragma once

class Operation;
class Cell;
#include "Value.h"

struct CellContext 
{
	CellContext() = default;
	CellContext(const Value& value);
	CellContext(Operation* op);
	CellContext(Cell* reference);

	Value value; //For SingleValueCell
	Operation* operation = nullptr; //For FormulaCell
	Cell* reference = nullptr; //For ReferencCell
	bool isEmpty = true;
};