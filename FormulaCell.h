#pragma once
#include "Cell.h"

//#include "FormulaName.h"

#include "Operation.h" //

template <typename T>
class FormulaCell : public Cell
{
private:
	Operation* operation;
public:
	FormulaCell(Operation* op);
	Cell* clone() const override;
};

