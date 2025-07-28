#pragma once

#include "CellContext.h"

#include "Cell.h"
#include "SingleValueCell.h"
#include "ReferenceCell.h"
#include "FormulaCell.h"
#include "EmptyCell.h"

class FactoryCell
{
public:
	static Cell* createCell(const CellContext& cellContext);
};

