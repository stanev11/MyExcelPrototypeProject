#pragma once
#include "Cell.h"

Cell::Cell(CellType type) : type(type)
{
}

int Cell::getRow() const
{
    return row;
}

int Cell::getCol() const
{
    return col;
}

void Cell::setRow(int row)
{
    if (row < 0)
    {
        throw std::invalid_argument("Invalid row argument!");
    }

    this->row = row;
}

void Cell::setCol(int col)
{
    if (col < 0)
    {
        throw std::invalid_argument("Invalid column argument!");
    }

    this->col = col;
}

const CellType& Cell::getCellType() const
{
    return type;
}

bool operator==(const Cell& lhs, const Cell& rhs)
{
    return lhs.getRow() == rhs.getRow() && lhs.getCol() == rhs.getCol();
}
