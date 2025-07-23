#include "CellParameter.h"

CellParameter::CellParameter(Cell* cell) : cell(cell)
{
    //TODO - nullptr !
}

IParameter* CellParameter::clone() const
{
    return new CellParameter(*this);
}

MyVector<double> CellParameter::getDoubleValues() const
{
    //TODO
    return MyVector<double>();
}
