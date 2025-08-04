#pragma once

class Operation;
class Cell;
#include "Value.h"

struct CellContext 
{
	Value value; //For SingleValueCell
	Operation* operation = nullptr; //For FormulaCell
	Cell* reference = nullptr; //For ReferencCell
	bool isEmpty = true;
};