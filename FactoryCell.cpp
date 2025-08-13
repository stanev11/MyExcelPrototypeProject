#include "FactoryCell.h"

Cell* FactoryCell::createCell(const CellContext& cellContext)
{
    //if (cellContext.operation != nullptr)
    //{
    //    return new FormulaCell(cellContext.operation);
    //}
    //else if (cellContext.reference != nullptr)
    //{
    //    return new ReferenceCell(cellContext.reference);
    //}
    //else if (cellContext.value.getType() != ValueType::EMPTY)
    //{
    //    return new SingleValueCell(cellContext.value);
    //}
    //return new EmptyCell();

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
