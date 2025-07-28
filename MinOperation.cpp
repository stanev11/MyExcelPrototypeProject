#include "MinOperation.h"


MinOperation::MinOperation(const RangeParameter& range) : range(range)
{
}

Operation* MinOperation::clone() const
{
    return new MinOperation(*this);
}

Value MinOperation::execute()
{
	double min = 0;
	bool hasNum = false;

	const MyVector<Value> values = range.getValues();

	for (size_t i = 0; i < values.getSize(); i++)
	{
		if (values[i].getType() == ValueType::INT || values[i].getType() == ValueType::DOUBLE)
		{
			if (min - values[i].getDoubleValue() > 0.0000000 || !hasNum)
			{
				min = values[i].getDoubleValue();
				hasNum = true;
			}
		}
	}

	if (!hasNum)
	{
		Value v;
		v.setErrorState();
		return v;
	}

	return Value(min);
}
