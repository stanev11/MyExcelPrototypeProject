#include "ConcatOperationParams.h"

#include "ConcatOperation.h"

ConcatOperationParams::ConcatOperationParams(const RangeParameter& range, char delim) : range(range),delimiter(delim)
{
}

Operation* ConcatOperationParams::create() const
{
    return new ConcatOperation(range, delimiter);
}
