#pragma once
#include "Property.h"

class InitialTableRows : public Property
{
private:
	int value;
public:
	InitialTableRows();
	InitialTableRows(int value);

	Property* clone() const override;
};

