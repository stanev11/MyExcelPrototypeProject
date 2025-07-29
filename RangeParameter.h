#pragma once

class Table;
class Cell;

#include "IParameter.h"

class RangeParameter : public IParameter
{
private:
	Cell* start = nullptr;
	Cell* end = nullptr;
	
	Table* table;
public:
	RangeParameter(Cell* start, Cell* end,Table* table);

	IParameter* clone() const override;
	MyVector<Value> getValues() const override;

	const Cell& getStart() const;
	const Cell& getEnd() const;
};

