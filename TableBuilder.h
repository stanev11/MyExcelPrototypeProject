#pragma once
#include "Table.h"
#include "fstream"

class TableBuilder
{
private:
	Table table;
public:
	TableBuilder();

	TableBuilder& setInitialTableRows(size_t count);
	TableBuilder& setInitialTableCols(size_t count);

	TableBuilder& setMaxTableRows(size_t count);
	TableBuilder& setMaxTableCols(size_t count);

	TableBuilder& setAutoFit(bool val);
	TableBuilder& setVisibleCellSymbols(size_t val);
	TableBuilder& setInitialAlignment(AlignmentType alignment);
	TableBuilder& setClearConsole(bool val);

	TableBuilder& setCell(int row, int col, Cell& cell);

	Table build();

	~TableBuilder();
};

