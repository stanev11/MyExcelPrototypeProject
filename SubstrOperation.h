#pragma once
#include "Operation.h"

class SubstrOperation : public Operation
{
private:
	IParameter* parameter;
	int startIndex;
	int length;
public:
	SubstrOperation(IParameter* parameter, int startIndex, int len);

	Operation* clone() const override;
	Value execute() override;
};

