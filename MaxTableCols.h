#pragma once
#include "Property.h"

class MaxTableCols : public Property
{
private:
	int value;
public:
	MaxTableCols();
	MaxTableCols(int value);

	Property* clone() const override;
};

