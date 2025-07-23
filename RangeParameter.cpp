#include "RangeParameter.h"

RangeParameter::RangeParameter(Cell* start, Cell* end) : start(start),end(end)
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
            //TODO - get cell from table
        }
    }

}
