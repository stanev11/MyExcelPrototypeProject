#pragma once
#include "Operation.h"

class MinOperation : public Operation
{
private:
	HeterogeneousContainer<IParameter> params;
public:
	MinOperation();
	MinOperation(const HeterogeneousContainer<IParameter>& params);

	Operation* clone() const override;
	Value execute() override;
};

