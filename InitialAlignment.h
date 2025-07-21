#pragma once
#include "Property.h"
#include "AlignmentType.h"

class InitialAlignment : public Property
{
private:
	AlignmentType type;
public:
	InitialAlignment();
	InitialAlignment(AlignmentType type);
	Property* clone() const override;
};

