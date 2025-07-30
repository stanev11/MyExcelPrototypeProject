#include "Table.h"

#include "CellContext.h"
#include "FactoryCell.h"

//Table::Table() : Table(INITIAL_ROWS,INITIAL_COLS)
//{
//}
//
//Table::Table(int rows, int cols)
//{
//    if (rows > 0) this->rows = rows;
//    if (cols > 0) this->cols = cols;
//
//    for (size_t i = 0; i < rows; i++)
//    {
//        for (size_t j= 0; j < cols; j++)
//        {
//            cells.insert(EmptyCell(), i * rows + j);
//        }
//    }
//}
//
//Table::Table(const HeterogeneousContainer<Cell>& cells) : cells(cells)
//{
//}

void Table::setInitialRows(size_t count)
{
    this->rows = count;
}

void Table::setInitialCols(size_t count)
{
    this->cols = count;
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

TableProperties& Table::getTableProps()
{
    return properties;
}

bool Table::isValidPosition(int row, int col) const
{
    return row <= rows && col <= cols;
}

bool Table::isEmpty(int row, int col) const
{
    return at(row,col).getValue().getType() == ValueType::EMPTY;
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

void Table::addCell(Cell& cell,int row,int col)
{
    if (!isValidPosition(row,col))
    {
        //throw - TODO
    }

    cell.setRow(row);
    cell.setCol(col);

    cells.insert(cell, row * cols + col);
}

void Table::addCell(Cell* cell,int row,int col)
{
    if (!isValidPosition(row,col))
    {
        //throw - TODO
    }

    if (cell != nullptr)
    {

        cell->setRow(row);
        cell->setCol(col);

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
    if (!isValidPosition(row, col))
    {
        //throw - TODO
    }

    cells.remove(row * rows + col);
}

const Cell& Table::at(int row,int col) const
{

    if (!isValidPosition(row,col))
    {
        //throw - TODO
    }

    return *cells[row * cols + col];
}

Cell& Table::at(int row,int col)
{
    if (!isValidPosition(row,col))
    {
        //throw - TODO
    }

    return *cells[row * cols + col];
}

void Table::insertAt(int row, int col, const CellContext& ctx)
{
    if (!isValidPosition(row,col))
    {
        //throw - TODO
    }

    removeCell(row, col);

    Cell* newCell = FactoryCell::createCell(ctx);

    addCell(newCell, row, col);

    newCell->setRow(row);
    newCell->setCol(col);
}

void Table::insertAt(Cell& cell, const CellContext& ctx)
{
    //int index = cells.find(cell);
    int row = cell.getRow();
    int col = cell.getCol();

    removeCell(cell);

    Cell* newCell = FactoryCell::createCell(ctx);

    /*cells.insert(*newCell, index);*/

    cell = *newCell;

    cell.setRow(row);
    cell.setCol(col);
}

void Table::deleteAt(int row, int col)
{
    if (!isValidPosition(row,col))
    {
        //throw - TODO
    }

    removeCell(row, col);

    addCell(new EmptyCell(), row, col);
}

