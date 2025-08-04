#include "SumOperationParams.h"
#include "SumOperation.h"

Operation* SumOperationParams::create() const
{
    return new SumOperation(params);
}
