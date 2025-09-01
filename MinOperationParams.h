#pragma once
#include "OperationParams.h"
#include "RangeParameter.h"

struct MinOperationParams : public OperationParams
{
	MinOperationParams() = default;

	MinOperationParams(const RangeParameter& range);

	RangeParameter range;

	Operation* create() const override;
};