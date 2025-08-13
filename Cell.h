#pragma once
#include "Value.h"
#include "CellType.h"
class Cell
{
private:
	int row;
	int col;

	CellType type;

public:
	Cell(CellType type);

	virtual Cell* clone() const = 0;
	virtual ~Cell() = default;

	virtual const Value& getValue() const = 0;

	virtual MyString toString() const = 0;

	int getRow() const;
	int getCol() const;

	void setRow(int row);
	void setCol(int col);

	const CellType& getCellType() const;
};

bool operator==(const Cell& lhs, const Cell& rhs);

