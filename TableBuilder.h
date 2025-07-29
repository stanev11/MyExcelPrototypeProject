#pragma once
#include "Table.h"

class TableBuilder
{
private:
	Table table;
public:
	TableBuilder();

	TableBuilder& addRows(size_t count);
	TableBuilder& addCols(size_t count);
	TableBuilder& setCell(int row, int col, Cell& cell);

	Table build();
};

