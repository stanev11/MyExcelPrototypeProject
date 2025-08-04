#include "FactoryOperation.h"

Operation* FactoryOperation::createOperation(const OperationParams& params)
{
	return params.create();
}
