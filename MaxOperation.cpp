#include "MaxOperation.h"

MaxOperation::MaxOperation(const RangeParameter& range) : range(range)
{ 
}

Operation* MaxOperation::clone() const
{
    return new MaxOperation(*this);
}

Value MaxOperation::execute()
{
	double max = 0;
	bool hasNum = false;

	const MyVector<Value> values = range.getValues();

	for (size_t i = 0; i < values.getSize(); i++)
	{
		if (values[i].getType() == ValueType::INT || values[i].getType() == ValueType::DOUBLE)
		{
			if (max - values[i].getDoubleValue() < 0.0000000 || !hasNum)
			{
				max = values[i].getDoubleValue();
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

	return Value(max);
}
