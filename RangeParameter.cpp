#include "RangeParameter.h"

#include "Table.h"

RangeParameter::RangeParameter(Cell* start, Cell* end,Table* table) : start(start),end(end),table(table), IParameter(ParameterType::RangeParameter)
{
    //TODO - nullptr !
}

IParameter* RangeParameter::clone() const
{
    return new RangeParameter(*this);
}

MyVector<Value> RangeParameter::getValues() const
{
    MyVector<Value> vec;
    
    int startRow = start->getRow();
    int startCol = start->getCol();

    int endRow = end->getRow();
    int endCol = end->getCol();

    for (size_t i = startRow; i <= endRow; i++)
    {
        for (size_t j = startCol; j <= endCol; j++)
        {
            const Value& value = table->at(i, j).getValue();

            vec.push_back(value);
        }
    }

    return vec;
}

const Cell& RangeParameter::getStart() const
{
    return *start;
}

const Cell& RangeParameter::getEnd() const
{
    return *end;
}

std::ofstream& RangeParameter::saveToBinaryFile(std::ofstream& ofs) const
{
    IParameter::saveToBinaryFile(ofs);

    int startRow = start->getRow();
    int startCol = start->getCol();

    ofs.write((const char*)&startRow, sizeof(int));
    ofs.write((const char*)&startCol, sizeof(int));

    int endRow = end->getRow();
    int endCol = end->getCol();

    ofs.write((const char*)&endRow, sizeof(int));
    ofs.write((const char*)&endCol, sizeof(int));

    return ofs;
}
