#pragma once
#include "Property.h"

class ClearConsoleAfterCommand : public Property
{
private:
	bool value;
public:
	ClearConsoleAfterCommand();
	ClearConsoleAfterCommand(bool value);
	Property* clone() const override;
};

