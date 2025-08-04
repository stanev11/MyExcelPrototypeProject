#pragma once

#include "HeterogeneousContainer.hpp"
#include "Cell.h"
#include "TableProperties.h"
#include "CellContext.h"

class Table
{
private:
	int rows = 0;
	int cols = 0;

	HeterogeneousContainer<Cell> cells;
	TableProperties properties;

public:
	void setInitialRows(size_t count);
	void setInitialCols(size_t count);

	int getRowsCount() const;
	int getColsCount() const;
	const TableProperties& getTableProps() const;
	TableProperties& getTableProps();

	bool isValidPosition(int row, int col) const;
	bool isEmpty(int row, int col) const;

	void addRow(size_t position);
	void addCol(size_t position);

	void removeCell(const Cell& cell);
	void removeCell(int row, int col);

	const Cell& at(int row,int col) const;
	Cell& at(int row,int col);

	void setCell(int row, int col, Cell* cell);
	void setCell(int row, int col, const Cell& cell);

	void insertAt(int row, int col,const Cell& cell);
	void insertAt(int row, int col, Cell* cell);
	void insertAt(int row, int col, const CellContext& ctx);
	void insertAt(int row, int col, const Value& value);

	void addCell(Cell* cell);
	void addCell(const Cell& cell);

	void deleteAt(int row, int col);

};

