#include "CountOperation.h"

CountOperation::CountOperation(const RangeParameter& range) : range(range)
{
}

Operation* CountOperation::clone() const
{
    return new CountOperation(*this);
}

Value CountOperation::execute()
{
    int counter = 0;

	MyVector<Value> values = range.getValues();

	for (size_t i = 0; i < values.getSize(); i++)
	{
		if (!values[i].isEmpty())
		{
			counter++;
		}
	}

	return counter;
}
