#include "FactoryCell.h"

Cell* FactoryCell::createCell(const CellContext& cellContext)
{
    if (cellContext.type == CellType::SingleValueCell)
    {
        return new SingleValueCell(cellContext.value);
    }
    else if (cellContext.type == CellType::ReferenceCell)
    {
        return new ReferenceCell(cellContext.reference);
    }
    else if (cellContext.type == CellType::FormulaCell)
    {
        return new FormulaCell(cellContext.operation);
    }
    return new EmptyCell();
}
