#pragma once
#include "MyVector.hpp"

class IParameter
{
public:
	virtual IParameter* clone() const = 0;
	virtual ~IParameter() = default;
};

