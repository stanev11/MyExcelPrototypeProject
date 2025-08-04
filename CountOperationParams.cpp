#include "CountOperationParams.h"

#include "CountOperation.h"

Operation* CountOperationParams::create() const
{
    return new CountOperation(range);
}
