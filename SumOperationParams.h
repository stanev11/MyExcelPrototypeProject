#pragma once
#include "OperationParams.h"
#include "SumOperation.h"
#include "IParameter.h"

struct SumOperationParams : public OperationParams
{
	HeterogeneousContainer<IParameter> params;

	SumOperationParams() = default;
	SumOperationParams(const HeterogeneousContainer<IParameter>& params);

	Operation* create() const override;
};