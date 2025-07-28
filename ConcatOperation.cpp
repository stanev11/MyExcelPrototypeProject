#include "ConcatOperation.h"

ConcatOperation::ConcatOperation(const RangeParameter& range, char delim) : range(range),delimiter(delim)
{
}

Operation* ConcatOperation::clone() const
{
    return new ConcatOperation(*this);
}

Value ConcatOperation::execute()
{
    MyString res;
	bool hasText = false;

	char* delim = new char(delimiter);

	MyString del(delim);

	const MyVector<Value>& values = range.getValues();

	for (size_t i = 0; i < values.getSize(); i++)
	{
		if (values[i].getType() == ValueType::STRING)
		{
			hasText = true;

			res += values[i].getStringValue();

			if (i < values.getSize() - 1)
			{
				res += del;
			}
		}
	}

	delete delim;

	if (!hasText)
	{
		Value v;
		v.setErrorState();
		return v;
	}

	return Value(res);
}
