#include "ReferenceCell.h"

ReferenceCell::ReferenceCell() : ReferenceCell(nullptr)
{
}

ReferenceCell::ReferenceCell(Cell* to) : Cell(CellType::ReferenceCell)
{
    if (to)
    {
        setRef(to);
    }
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

void ReferenceCell::setRef(Cell* to)
{
    if (to)
    {
        this->to = to;
        to->addRefCell(this);
    }
}
