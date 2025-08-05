#pragma once
#include "Operation.h"
#include "IParameter.h"
#include "HeterogeneousContainer.hpp"

class SumOperation : public Operation
{
private:
	HeterogeneousContainer<IParameter> params;
public:
	SumOperation();
	SumOperation(const HeterogeneousContainer<IParameter>& params);

	void addParameter(IParameter* parameter);

	Operation* clone() const override;
	Value execute() override;

};

