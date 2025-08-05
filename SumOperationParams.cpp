#include "SumOperationParams.h"

Operation* SumOperationParams::create() const
{
    return new SumOperation(params);
}
