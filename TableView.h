#pragma once

#include "Table.h"

class TableView
{
private:
	const Table& table;

	void clearConsole() const;
	MyString formatCellContent(const Cell& cell, int width, AlignmentType alignment) const;

public:
	TableView(const Table& table);

	void render();
};

