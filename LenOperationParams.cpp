#include "LenOperationParams.h"

#include "LenOperation.h"

Operation* LenOperationParams::create() const
{
    return new LenOperation(param);
}
