#include "Operation.h"

Operation::Operation(const FormulaType& formulaType) : formulaType(formulaType)
{
}

FormulaType Operation::getFormulaType() const
{
	return formulaType;
}
