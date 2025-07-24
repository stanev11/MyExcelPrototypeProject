#include "EmptyCell.h"

Cell* EmptyCell::clone() const
{
    return new EmptyCell(*this);
}

const Value& EmptyCell::getValue() const
{
    return Value();
}
