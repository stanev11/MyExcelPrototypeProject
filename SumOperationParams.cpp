#include "SumOperationParams.h"

SumOperationParams::SumOperationParams(const HeterogeneousContainer<IParameter>& params) : params(params)
{
}

Operation* SumOperationParams::create() const
{
    return new SumOperation(params);
}
