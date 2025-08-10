#include "CellParameter.h"
#include "Cell.h"

CellParameter::CellParameter(Cell* cell) : cell(cell),IParameter(ParameterType::CellParameter)
{
    //TODO - nullptr !
}

IParameter* CellParameter::clone() const
{
    return new CellParameter(*this);
}

MyVector<Value> CellParameter::getValues() const
{
    MyVector<Value> vec;
    vec.push_back(cell->getValue());

    return vec;
}

const Cell& CellParameter::getCell() const
{
    return *cell;
}

