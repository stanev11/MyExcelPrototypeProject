#include "CountOperationParams.h"

#include "CountOperation.h"

CountOperationParams::CountOperationParams(const RangeParameter& range) : range(range)
{
}

Operation* CountOperationParams::create() const
{
    return new CountOperation(range);
}
