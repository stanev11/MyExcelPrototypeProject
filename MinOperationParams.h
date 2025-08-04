#pragma once
#include "OperationParams.h"
#include "RangeParameter.h"

struct MinOperationParams : public OperationParams
{
	RangeParameter range;

	Operation* create() const override;
};