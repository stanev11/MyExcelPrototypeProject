#include "AverageOperationParams.h"

#include "AverageOperation.h"

Operation* AverageOprationParams::create() const
{
    return new AverageOperation(params);
}
