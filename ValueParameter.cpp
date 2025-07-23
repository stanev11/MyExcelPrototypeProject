#include "ValueParameter.hpp"

ValueParameter::ValueParameter(const Value& value) : value(value)
{
}

IParameter* ValueParameter::clone() const
{
	return new ValueParameter(*this);
}
