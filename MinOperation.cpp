#include "MinOperation.h"

MinOperation::MinOperation()
{
}

MinOperation::MinOperation(const HeterogeneousContainer<IParameter>& params) : params(params)
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

	for (size_t i = 0; i < params.getSize(); i++)
	{
		MyVector<Value> currentVals = params[i]->getValues();
		size_t count = currentVals.getSize();

		for (size_t j = 0; j < count; j++)
		{
			if (currentVals[j].getType() == ValueType::INT || currentVals[j].getType() == ValueType::DOUBLE)
			{
				if (min - currentVals[j].getDoubleValue() > 0.0000000 || !hasNum)
				{
					min = currentVals[j].getDoubleValue();
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

	return Value(min);
}
