#include "ReferenceCell.h"

ReferenceCell::ReferenceCell() : to(nullptr)
{
}

ReferenceCell::ReferenceCell(Cell* to) : to(to)
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
