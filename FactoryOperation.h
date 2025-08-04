#pragma once

#include "OperationParams.h"

class FactoryOperation
{
public:
	static Operation* createOperation(const OperationParams& params);
};

