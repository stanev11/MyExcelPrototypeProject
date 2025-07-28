#pragma once
#include "Value.h";

class Cell
{
private:
	int row;
	int col;
public:
	virtual Cell* clone() const = 0;
	virtual ~Cell() = default;

	virtual const Value& getValue() const = 0;

	virtual MyString toString() const = 0;

	int getRow() const;
	int getCol() const;

	void setRow(int row);
	void setCol(int col);
};

