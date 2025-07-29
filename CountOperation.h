#pragma once
#include "Operation.h"
#include "RangeParameter.h"

class CountOperation : public Operation
{
private:
	RangeParameter range;
public:
	CountOperation(const RangeParameter& range);

	Operation* clone() const override;
	Value execute() override;
};

