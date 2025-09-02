#include "MaxOperation.h"

#include "Cell.h"

MaxOperation::MaxOperation(const RangeParameter& range) : range(range),Operation(FormulaType::MAX)
{ 
}

Operation* MaxOperation::clone() const
{
    return new MaxOperation(*this);
}

Value MaxOperation::execute()
{
	double max = INT_MIN;
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

bool MaxOperation::hasCircularReference(const Cell& cell) const
{
	const Cell& start = range.getStart();
	const Cell& end = range.getEnd();

	return start.getRow() <= cell.getRow() && end.getRow() >= cell.getRow()
		&& start.getCol() <= cell.getCol() && end.getCol() >= cell.getCol();
}

std::ofstream& MaxOperation::saveToBinaryFile(std::ofstream& ofs) const
{
	Operation::saveToBinaryFile(ofs);

	range.saveToBinaryFile(ofs);

	return ofs;
}
