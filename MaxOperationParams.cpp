#include "MaxOperationParams.h"

#include "MaxOperation.h"

MaxOperationParams::MaxOperationParams(const RangeParameter& range) : range(range)
{
}

Operation* MaxOperationParams::create() const
{
    return new MaxOperation(range);
}
