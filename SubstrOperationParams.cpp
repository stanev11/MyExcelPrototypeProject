#include "SubstrOperationParams.h"

#include "SubstrOperation.h"

Operation* SubstrOperationParams::create() const
{
    return new SubstrOperation(parameter, startIndex, length);
}
