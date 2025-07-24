#include "MaxOperation.h"

MaxOperation::MaxOperation()
{
}

MaxOperation::MaxOperation(const HeterogeneousContainer<IParameter>& params) : params(params)
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

	for (size_t i = 0; i < params.getSize(); i++)
	{
		MyVector<Value> currentVals = params[i]->getValues();
		size_t count = currentVals.getSize();

		for (size_t j = 0; j < count; j++)
		{
			if (currentVals[j].getType() == ValueType::INT || currentVals[j].getType() == ValueType::DOUBLE)
			{
				if (max - currentVals[j].getDoubleValue() < 0.0000000 || !hasNum)
				{
					max = currentVals[j].getDoubleValue();
					hasNum = true;
				}
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
