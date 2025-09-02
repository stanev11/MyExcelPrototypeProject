#pragma once
#include "OperationParams.h"
#include "RangeParameter.h"

struct ConcatOperationParams : public OperationParams
{
	ConcatOperationParams() = default;
	ConcatOperationParams(const RangeParameter& range,char delim);

	RangeParameter range;
	char delimiter;

	Operation* create() const override;
};