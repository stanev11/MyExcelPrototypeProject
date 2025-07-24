#include "Table.h"

#include "EmptyCell.h"

Table::Table()
{
}

Table::Table(int rows, int cols)
{
    if (rows > 0) this->rows = rows;
    if (cols > 0) this->cols = cols;
}

Table::Table(const HeterogeneousContainer<Cell>& cells) : cells(cells)
{
}

int Table::getRowsCount() const
{
    return rows;
}

int Table::getColsCount() const
{
    return cols;
}

const TableProperties& Table::getTableProps() const
{
    return properties;
}

void Table::addRow(size_t position)
{
    //TODO
    cells.resizeAt(position, cols);

    rows++;
}

void Table::addCol(size_t position)
{
    //TODO
    for (int i = rows-1; i >= 0; i--)
    {
        cells.insert(EmptyCell(), i * cols + position);
    }

    cols++;
}

void Table::addCell(const Cell& cell,int row,int col)
{
    cells.insert(cell, row * cols + col);
}

void Table::addCell(Cell* cell,int row,int col)
{
    if (cell != nullptr)
    {
        cells.insert(*cell, row * cols + col);
    }
    else
    {
        //TODO - throw
    }
}

void Table::removeCell(const Cell& cell)
{
    int index = cells.find(cell);

    cells.remove(index);
}

void Table::removeCell(int row, int col)
{
    cells.remove(row * rows + col);
}

const Cell& Table::at(int row,int col) const
{
    return *cells[row * cols + col];
}

Cell& Table::at(int row,int col)
{
    return *cells[row * cols + col];
}
