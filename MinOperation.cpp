#include "MinOperation.h"
#include "Cell.h"

MinOperation::MinOperation(const RangeParameter& range) : range(range)
{
}

Operation* MinOperation::clone() const
{
    return new MinOperation(*this);
}

Value MinOperation::execute()
{
	double min = INT_MAX;
	bool hasNum = false;

	const MyVector<Value> values = range.getValues();

	for (size_t i = 0; i < values.getSize(); i++)
	{
		if (values[i].getType() == ValueType::INT)
		{
			if (min > values[i].getIntValue() || !hasNum)
			{
				min = values[i].getIntValue();
				hasNum = true;
			}
		}
		else if (values[i].getType() == ValueType::DOUBLE)
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