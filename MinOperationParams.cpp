#include "MinOperationParams.h"

#include "MinOperation.h"

Operation* MinOperationParams::create() const
{
    return new MinOperation(range);
}
