#pragma once
#include "Cell.h"

#include "ReferenceCell.h"

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

std::ofstream& Cell::saveToBinaryFile(std::ofstream& ofs) const
{
    if (!ofs.is_open())
    {
        throw std::logic_error("Couldn't open file to write!");
    }

    ofs.write((const char*)&row, sizeof(row));
    ofs.write((const char*)&col, sizeof(col));

    ofs.write((const char*)&type, sizeof(int));

    return ofs;
}

void Cell::addRefCell(Cell* cell)
{
    if (cell)
    {
        refCells.addObject(cell);
    }
}

//void Cell::updateRefCells()
//{
//    for (size_t i = 0; i < refCells.getSize(); i++)
//    {
//        refCells[i]->updateRefCells();
//
//        if (refCells[i]->getCellType() == CellType::ReferenceCell)
//        {
//            ReferenceCell* ref = dynamic_cast<ReferenceCell*>(refCells[i]);
//            ref->setRef(this);
//        }
//    }
//}

void Cell::transferRefCells(Cell* newCell)
{
    if (newCell)
    {
        for (size_t i = 0; i < refCells.getSize(); i++)
        {
            dynamic_cast<ReferenceCell*>(refCells[i])->setRef(newCell);
        }
    }
}

bool operator==(const Cell& lhs, const Cell& rhs)
{
    return lhs.getRow() == rhs.getRow() && lhs.getCol() == rhs.getCol();
}
