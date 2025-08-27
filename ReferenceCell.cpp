#include "ReferenceCell.h"

ReferenceCell::ReferenceCell() : ReferenceCell(nullptr)
{
}

ReferenceCell::ReferenceCell(Cell* to) : to(to), Cell(CellType::ReferenceCell)
{
}

Cell* ReferenceCell::clone() const
{
    return new ReferenceCell(*this);
}

void ReferenceCell::release()
{
    to = nullptr;
}

const Value& ReferenceCell::getValue() const
{
    return to->getValue();
}

MyString ReferenceCell::toString() const
{
    return to->toString();
}

std::ofstream& ReferenceCell::saveToBinaryFile(std::ofstream& ofs) const
{
    Cell::saveToBinaryFile(ofs);

    to->saveToBinaryFile(ofs);

    return ofs;
}
