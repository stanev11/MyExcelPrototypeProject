#pragma once
#include "OperationParams.h"
#include "AverageOperation.h"
#include "IParameter.h"

struct AverageOprationParams : public OperationParams
{
	HeterogeneousContainer<IParameter> params;

	AverageOprationParams(const HeterogeneousContainer<IParameter>& params);

	Operation* create() const override;
};
