#include "ConcatOperationParams.h"

#include "ConcatOperation.h"

Operation* ConcatOparationParams::create() const
{
    return new ConcatOperation(range, delimiter);
}
