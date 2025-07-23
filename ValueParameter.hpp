#pragma once
#include "IParameter.h"
#include "Value.h"

class ValueParameter : public IParameter
{
private:
	Value value;

public:
	ValueParameter(const Value& value);
	IParameter* clone() const override;
};