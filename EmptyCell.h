#pragma once

#include "Cell.h"

class EmptyCell : public Cell
{
public:
	
	Cell* clone() const override;
	const Value& getValue() const override;
};

