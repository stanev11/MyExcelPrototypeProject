#include "MaxTableRows.h"

MaxTableRows::MaxTableRows() : MaxTableRows(0)
{
}

MaxTableRows::MaxTableRows(int value) : Property(PropertyType::MaxTableRows),value(value)
{
}

Property* MaxTableRows::clone() const
{
    return new MaxTableRows(*this);
}
