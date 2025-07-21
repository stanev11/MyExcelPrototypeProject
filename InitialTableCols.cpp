#include "InitialTableCols.h"

InitialTableCols::InitialTableCols() : InitialTableCols(0)
{
}

InitialTableCols::InitialTableCols(int value) : Property(PropertyType::InitialTableCols), value(value)
{
}

Property* InitialTableCols::clone() const
{
    return new InitialTableCols(*this);
}
