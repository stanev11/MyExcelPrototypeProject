#include "SingleValueCell.h"

SingleValueCell::SingleValueCell() : Cell(CellType::SingleValueCell)
{
}

SingleValueCell::SingleValueCell(const Value& value) : value(value),Cell(CellType::SingleValueCell)
{
}

Cell* SingleValueCell::clone() const
{
    return new SingleValueCell(*this);
}

const Value& SingleValueCell::getValue() const
{
    return value;
}

MyString SingleValueCell::toString() const
{
    return value.toString();
}
