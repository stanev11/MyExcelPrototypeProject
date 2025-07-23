#pragma once

#include "Cell.h" //

#include "IParameter.h"

class RangeParameter : public IParameter
{
private:
	Cell* start = nullptr;
	Cell* end = nullptr;
public:
	RangeParameter(Cell* start, Cell* end);

	IParameter* clone() const override;
	MyVector<Value> getValues() const override;
};

