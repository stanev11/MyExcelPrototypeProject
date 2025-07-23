
#include "ValueParameter.h"

ValueParameter::ValueParameter(const Value& value) : value(value)
{
}

IParameter* ValueParameter::clone() const
{
	return new ValueParameter(*this);
}

MyVector<Value> ValueParameter::getValues() const
{
	// TODO: insert return statement here

	MyVector<Value> vec;
	vec.push_back(value);
	return vec;
}
