#pragma once
#include "PropertyType.h"

class Property
{
protected:
	PropertyType type;
public:
	Property();
	Property(PropertyType type);

	virtual Property* clone() const = 0;
	virtual ~Property() = default;
};

