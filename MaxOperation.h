#pragma once
#include "Operation.h"

class MaxOperation : public Operation
{
private:
	HeterogeneousContainer<IParameter> params;
public:
	MaxOperation();
	MaxOperation(const HeterogeneousContainer<IParameter>& params);

	Operation* clone() const override;
	Value execute() override;
};

