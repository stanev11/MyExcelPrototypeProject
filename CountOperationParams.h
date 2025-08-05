#pragma once
#include "OperationParams.h"
#include "RangeParameter.h"

struct CountOperationParams : public OperationParams
{
	CountOperationParams(const RangeParameter& range);

	RangeParameter range;

	Operation* create() const override;
};