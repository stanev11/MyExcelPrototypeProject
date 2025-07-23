#pragma once
#include "Operation.h"

class AverageOperation : public Operation
{
private:
	HeterogeneousContainer<IParameter> params;

public:
	AverageOperation();
	AverageOperation(const HeterogeneousContainer<IParameter>& params);

	Operation* clone() const override;
	Value execute() override;
};

