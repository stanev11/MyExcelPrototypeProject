#include "InitialTableRows.h"

InitialTableRows::InitialTableRows() : InitialTableRows(0)
{
}

InitialTableRows::InitialTableRows(int value) : Property(PropertyType::InitialTableRows), value(value)
{
}

Property* InitialTableRows::clone() const
{
    return new InitialTableRows(*this);
}
