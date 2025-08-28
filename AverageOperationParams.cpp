#include "AverageOperationParams.h"

AverageOprationParams::AverageOprationParams(const HeterogeneousContainer<IParameter>& params) : params(params)
{
}

Operation* AverageOprationParams::create() const
{
    return new AverageOperation(params);
}
