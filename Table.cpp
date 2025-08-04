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

void Table::setCell(int row, int col, Cell* cell)
{
    if (!isValidPosition(row, col))
    {
        //TODO
    }

    at(row, col) = *cell;
}

void Table::setCell(int row, int col, const Cell& cell)
{
    if (!isValidPosition(row, col))
    {
        //TODO
    }

    at(row, col) = cell;
}

void Table::insertAt(int row, int col,const Cell& cell)
{
    if (!isValidPosition(row, col))
    {
        //TODO
    }

    cells[row * cols + col] = cell.clone();

    cells[row * cols + col]->setRow(row);
    cells[row * cols + col]->setCol(col);
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

    cells[row * cols + col] = cell;
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

