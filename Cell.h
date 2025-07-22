#pragma once

class Cell
{
protected:
	int row;
	int col;
public:
	virtual Cell* clone() const = 0;
	virtual ~Cell() = default;
};

