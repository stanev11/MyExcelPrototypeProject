#pragma once

#include "Property.h"

class MaxTableRows : public Property
{
private:
	int value;
public:
	MaxTableRows();
	MaxTableRows(int value);

	Property* clone() const override;

};

