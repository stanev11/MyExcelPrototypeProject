#include "CellParameter.h"

CellParameter::CellParameter(Cell* cell) : cell(cell)
{
    //TODO - nullptr !
}

IParameter* CellParameter::clone() const
{
    return new CellParameter(*this);
}
