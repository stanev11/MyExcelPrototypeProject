#include "IParameter.h"

IParameter::IParameter(const ParameterType& type) : type(type)
{
}

const ParameterType& IParameter::getType() const
{
	return type;
}
