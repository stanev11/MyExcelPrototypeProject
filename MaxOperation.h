#pragma once
#include "RangeParameter.h"
#include "Operation.h"

class MaxOperation : public Operation
{
private:
	RangeParameter range;
public:

	MaxOperation(const RangeParameter& range);

	Operation* clone() const override;
	Value execute() override;

	bool hasCircularReference(const Cell& cell) const override;
};

