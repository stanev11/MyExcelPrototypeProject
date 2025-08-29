#include "Table.h"

#include "CellContext.h"
#include "FactoryCell.h"

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

void Table::removeCell(const Cell& cell)
{
    try
    {
        int index = cells.find(cell);

        cells.remove(index);
    }
    catch (const std::exception&)
    {

    }
}

void Table::removeCell(int row, int col)
{
    if (!isValidPosition(row, col))
    {
        //throw - TODO
        return;
    }

    cells.remove((row-1) * cols + (col-1));
}

const Cell& Table::at(int row,int col) const
{

    if (!isValidPosition(row,col))
    {
        //throw - TODO
    }

    return *cells[(row - 1) * cols + (col - 1)];
}

Cell& Table::at(int row,int col)
{
    if (!isValidPosition(row,col))
    {
        //throw - TODO
    }

    return *cells[(row - 1) * cols + (col - 1)];
}

//void Table::setCell(int row, int col, Cell* cell)
//{
//    if (!isValidPosition(row, col))
//    {
//        //TODO
//    }
//    Cell& current = at(row, col);
//    current = *cell;
//    std::cout<<current.toString();
//}

void Table::setCell(int row, int col, const Cell& cell)
{
    if (!isValidPosition(row, col))
    {
        //TODO
    }

    cells[(row - 1) * cols + (col - 1)] = cell.clone();
}

void Table::insertAt(int row, int col,const Cell& cell)
{
    if (!isValidPosition(row, col))
    {
        //TODO
    }

    cells[(row - 1) * cols + (col - 1)] = cell.clone();

    cells[(row - 1) * cols + (col - 1)]->setRow(row);
    cells[(row - 1) * cols + (col - 1)]->setCol(col);
}

void Table::insertAt(int row, int col, Cell* cell)
{
    if (cell == nullptr)
    {
        throw std::invalid_argument("Nullptr!");
    }

    if (!isValidPosition(row, col))
    {
        //TODO - throw
    }

    cell->setRow(row);
    cell->setCol(col);

    cells[(row-1) * cols + (col-1)] = cell;
}

void Table::insertAt(int row, int col, const CellContext& ctx)
{
    if (!isValidPosition(row, col))
    {
        //TOOD
    }

    Cell* newCell = FactoryCell::createCell(ctx);

    setCell(row, col, *newCell);
}

void Table::insertAt(int row, int col, const Value& value)
{
    CellContext ctx;
    ctx.value = value;

    insertAt(row, col, ctx);
}

void Table::addCell(Cell* cell)
{
    if (cell == nullptr)
    {
        throw std::invalid_argument("Nullptr!");
    }

    cells.addObject(cell);
}

void Table::addCell(const Cell& cell)
{
    cells.addObject(cell);
}

void Table::deleteAt(int row, int col)
{
    if (!isValidPosition(row, col))
    {
        throw std::invalid_argument("Invalid row or col!");
    }

    Cell& cell = at(row, col);

    setCell(row, col, EmptyCell());
}

