#include "TableBuilder.h"

#include "EmptyCell.h"

TableBuilder::TableBuilder()
{
}

TableBuilder& TableBuilder::setInitialTableRows(size_t count)
{
    table.setInitialRows(count);

    table.getTableProps().initialTableRows = count;

    return *this;
}

TableBuilder& TableBuilder::setInitialTableCols(size_t count)
{
    table.setInitialCols(count);

    table.getTableProps().initialTableCols = count;

    return *this;
}

TableBuilder& TableBuilder::setMaxTableRows(size_t count)
{
    table.getTableProps().maxTableRows = count;

    return *this;
}

TableBuilder& TableBuilder::setMaxTableCols(size_t count)
{
    table.getTableProps().maxTableCols = count;

    return *this;
}

TableBuilder& TableBuilder::setAutoFit(bool val)
{
    table.getTableProps().autoFit = val;

    return *this;
}

TableBuilder& TableBuilder::setVisibleCellSymbols(size_t count)
{
    table.getTableProps().visibleCellSymbols = count;

    return *this;
}

TableBuilder& TableBuilder::setInitialAlignment(AlignmentType alignment)
{
    table.getTableProps().initialAlignment = alignment;

    return *this;
}

TableBuilder& TableBuilder::setClearConsole(bool val)
{
    table.getTableProps().clearConsoleAfterCommand = val;

    return *this;
}

TableBuilder& TableBuilder::setCell(int row, int col, Cell& cell)
{
    table.at(row,col)=cell;

    return *this;
}

Table TableBuilder::build()
{
    //TODO
    for (size_t i = 0; i < table.getRowsCount(); i++)
    {
        for (size_t j = 0; j < table.getColsCount(); j++)
        {
           /*table.setCell(i, j,EmptyCell());*/
            table.addCell(EmptyCell());
        }
    }

    return std::move(table);
}
