#pragma once
#include "OperationParams.h"
#include "RangeParameter.h"

struct MaxOperationParams : public OperationParams
{
	RangeParameter range;

	Operation* create() const override;
};