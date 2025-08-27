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

std::ofstream& CellParameter::saveToBinaryFile(std::ofstream& ofs) const
{
    IParameter::saveToBinaryFile(ofs);

    int row = cell->getRow();
    int col = cell->getCol();

    ofs.write((const char*)&row, sizeof(int)); 
    ofs.write((const char*)&col, sizeof(int));

    return ofs;
}

