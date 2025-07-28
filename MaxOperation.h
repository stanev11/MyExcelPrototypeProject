#pragma once
#include "RangeParameter.h"
#include "Operation.h"

class MaxOperation : public Operation
{
private:
	RangeParameter range;
public:
	//MaxOperation(); //
	MaxOperation(const RangeParameter& range);

	Operation* clone() const override;
	Value execute() override;
};

