#include "MaxOperationParams.h"

#include "MaxOperation.h"

Operation* MaxOperationParams::create() const
{
    return new MaxOperation(range);
}
