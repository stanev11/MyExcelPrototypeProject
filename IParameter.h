#pragma once
#include "MyVector.hpp"
#include "Value.h"

class IParameter
{
public:
	virtual IParameter* clone() const = 0;
	virtual ~IParameter() = default;

	virtual MyVector<Value> getValues() const = 0;
};

