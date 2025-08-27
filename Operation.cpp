#include "Operation.h"

Operation::Operation(const FormulaType& formulaType) : formulaType(formulaType)
{
}

FormulaType Operation::getFormulaType() const
{
	return formulaType;
}

std::ofstream& Operation::saveToBinaryFile(std::ofstream& ofs) const
{
    if (!ofs.is_open())
    {
        throw std::logic_error("File is not open for writing!");
    }

    ofs.write((const char*)(int)&formulaType, sizeof(int));

    return ofs;
}
