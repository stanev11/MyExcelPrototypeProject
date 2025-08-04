#pragma once
#include "OperationParams.h"
#include "RangeParameter.h"

struct ConcatOparationParams : public OperationParams
{
	RangeParameter range;
	char delimiter;

	Operation* create() const override;
};