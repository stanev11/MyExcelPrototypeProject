#include "TableBuilder.h"

TableBuilder::TableBuilder()
{
}

TableBuilder& TableBuilder::addRows(size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        table.addRow(table.getRowsCount());
    }

    return *this;
}

TableBuilder& TableBuilder::addCols(size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        table.addCol(table.getColsCount());
    }

    return *this;
}

TableBuilder& TableBuilder::setCell(int row, int col, Cell& cell)
{
    table.addCell(cell, row, col);

    return *this;
}

Table TableBuilder::build()
{
    //TODO
    return std::move(table);
}
