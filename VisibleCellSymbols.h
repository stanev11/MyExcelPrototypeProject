#pragma once

#include "Property.h"

class VisibleCellSymbols : public Property
{
private:
	int value;
public: 
	VisibleCellSymbols();
	VisibleCellSymbols(int value);

	Property* clone() const override;
};

