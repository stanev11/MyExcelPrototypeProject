#include "InitialAlignment.h"

InitialAlignment::InitialAlignment() : InitialAlignment(AlignmentType::left)
{
}

InitialAlignment::InitialAlignment(AlignmentType type) : Property(PropertyType::InitialAlignment),type(type)
{
}

Property* InitialAlignment::clone() const
{
    return new InitialAlignment(*this);
}
