#pragma once
#include "Operation.h"
#include "IParameter.h"
#include "HeterogeneousContainer.hpp"

class AverageOperation : public Operation
{
private:
	HeterogeneousContainer<IParameter> params;

public:
	AverageOperation();
	AverageOperation(const HeterogeneousContainer<IParameter>& params);

	Operation* clone() const override;
	Value execute() override;

	bool hasCircularReference(const Cell& cell) const;
};

