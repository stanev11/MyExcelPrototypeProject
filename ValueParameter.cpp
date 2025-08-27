
#include "ValueParameter.h"

ValueParameter::ValueParameter(const Value& value) : value(value), IParameter(ParameterType::ValueParameter)
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

std::ofstream& ValueParameter::saveToBinaryFile(std::ofstream& ofs) const
{
	IParameter::saveToBinaryFile(ofs);

	value.saveToBinaryFile(ofs);

	return ofs;
}
