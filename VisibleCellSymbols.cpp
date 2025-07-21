#include "VisibleCellSymbols.h"

VisibleCellSymbols::VisibleCellSymbols() : VisibleCellSymbols(0)
{
}

VisibleCellSymbols::VisibleCellSymbols(int value) : Property(PropertyType::VisibleCellSymbols),value(value)
{
}

Property* VisibleCellSymbols::clone() const
{
    return new VisibleCellSymbols(*this);
}
