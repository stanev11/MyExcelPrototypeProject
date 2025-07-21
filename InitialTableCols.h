#pragma once
#include "Property.h"

class InitialTableCols : public Property
{
private:
	int value;
public:
	InitialTableCols();
	InitialTableCols(int value);

	Property* clone() const override;
};

