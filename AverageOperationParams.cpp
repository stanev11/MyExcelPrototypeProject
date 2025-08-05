#include "AverageOperationParams.h"

Operation* AverageOprationParams::create() const
{
    return new AverageOperation(params);
}
