#include "RangeParameter.h"

RangeParameter::RangeParameter(Cell* start, Cell* end) : start(start),end(end)
{
    //TODO - nullptr !
}

IParameter* RangeParameter::clone() const
{
    return new RangeParameter(*this);
}
