#pragma once
#include "Value.h"
#include "CellType.h"
#include "HeterogeneousContainer.hpp"

class Cell
{
private:
	int row;
	int col;

	CellType type;
	HeterogeneousContainer<Cell> refCells;
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

	virtual std::ofstream& saveToBinaryFile(std::ofstream& ofs) const;

	void addRefCell(Cell* cell);
	//void updateRefCells();

	void transferRefCells(Cell* newCell);
};

bool operator==(const Cell& lhs, const Cell& rhs);

