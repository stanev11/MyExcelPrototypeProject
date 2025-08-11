#pragma once
#include "OperationParams.h"
#include "RangeParameter.h"

struct MaxOperationParams : public OperationParams
{
	MaxOperationParams(const RangeParameter& range);

	RangeParameter range;

	Operation* create() const override;
};