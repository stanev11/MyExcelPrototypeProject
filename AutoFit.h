#pragma once
#include "Property.h"

class AutoFit : public Property
{
private:
	bool value;
public:
	AutoFit();
	AutoFit(bool value);
	Property* clone() const override;
};

