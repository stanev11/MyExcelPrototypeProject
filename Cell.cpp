#pragma once
#include "Cell.h"

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
