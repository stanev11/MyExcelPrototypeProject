#pragma once

#include "Cell.h"

class EmptyCell : public Cell
{
private:
	Value value;
public:
	EmptyCell();

	Cell* clone() const override;
	const Value& getValue() const override;
	
	MyString toString() const override;
};

