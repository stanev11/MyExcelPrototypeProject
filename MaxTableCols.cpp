#include "MaxTableCols.h"

MaxTableCols::MaxTableCols() : MaxTableCols(0)
{
}

MaxTableCols::MaxTableCols(int value) : Property(PropertyType::MaxTableCols),value(value)
{
}

Property* MaxTableCols::clone() const
{
    return new MaxTableCols(*this);
}
