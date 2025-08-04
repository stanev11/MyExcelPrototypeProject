#pragma once
#include "OperationParams.h"
#include "HeterogeneousContainer.hpp"
#include "IParameter.h"

struct SumOperationParams : public OperationParams
{
	HeterogeneousContainer<IParameter> params;

	Operation* create() const override;
};