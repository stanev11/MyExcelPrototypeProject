#pragma once
#include "IParameter.h"

template <typename T>
class ValueParameter
{
private:
	T value;
public:
	ValueParameter(const T& value);
	IParameter* clone() const override;
};

template<typename T>
inline ValueParameter<T>::ValueParameter(const T& value) : value(value)
{
}

template<typename T>
inline IParameter* ValueParameter<T>::clone() const
{
	return new ValueParameter<T>(*this);
}
