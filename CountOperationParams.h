#pragma once
#include "OperationParams.h"
#include "RangeParameter.h"

struct CountOperationParams : public OperationParams
{
	RangeParameter range;

	Operation* create() const override;
};