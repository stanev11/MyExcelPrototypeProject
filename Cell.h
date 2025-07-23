#pragma once
#include "Value.h";

class Cell
{
protected:
	int row;
	int col;
public:
	virtual Cell* clone() const = 0;
	virtual ~Cell() = default;

	virtual const Value& getValue() const = 0;

	int getRow() const;
	int getCol() const;
};

