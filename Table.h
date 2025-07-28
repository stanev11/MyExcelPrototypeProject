#pragma once

#include "HeterogeneousContainer.hpp"
#include "Cell.h"
#include "TableProperties.h"

class Table
{
private:
	int rows = 0;
	int cols = 0;

	HeterogeneousContainer<Cell> cells;
	TableProperties properties;

public:
	Table();
	Table(int rows, int cols);
	Table(const HeterogeneousContainer<Cell>& cells);

	int getRowsCount() const;
	int getColsCount() const;
	const TableProperties& getTableProps() const;

	bool isValidPosition(int row, int col) const;
	bool isEmpty(int row, int col) const;

	void addRow(size_t position);
	void addCol(size_t position);

	void addCell(Cell& cell,int row,int col);
	void addCell(Cell* cell,int row,int col);

	void removeCell(const Cell& cell);
	void removeCell(int row, int col);

	const Cell& at(int row,int col) const;
	Cell& at(int row,int col);

	void insertAt(int row, int col, const CellContext& ctx);
	void insertAt(Cell& cell, const CellContext& ctx);

	void deleteAt(int row, int col);

};

