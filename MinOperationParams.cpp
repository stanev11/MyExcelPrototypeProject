#include "MinOperationParams.h"

#include "MinOperation.h"

MinOperationParams::MinOperationParams(const RangeParameter& range) : range(range)
{
}

Operation* MinOperationParams::create() const
{
    return new MinOperation(range);
}
