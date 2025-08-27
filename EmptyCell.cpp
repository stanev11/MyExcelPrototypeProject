#include "EmptyCell.h"

EmptyCell::EmptyCell() : Cell(CellType::Empty)
{
}

Cell* EmptyCell::clone() const
{
    return new EmptyCell(*this);
}

const Value& EmptyCell::getValue() const
{
    return value;
}

MyString EmptyCell::toString() const
{
    return MyString();
}

std::ofstream& EmptyCell::saveToBinaryFile(std::ofstream& ofs) const
{
    Cell::saveToBinaryFile(ofs);

   // value.saveToBinaryFile(ofs); //not sure if needed (value is default)

    return ofs;
}

