#pragma once

#include "Cell.h"
#include "Value.h"

class SingleValueCell : public Cell
{
private:
	Value value;
public:
	SingleValueCell();
	SingleValueCell(const Value& value);

	Cell* clone() const override;

	const Value& getValue() const override;

	MyString toString() const override;
};
