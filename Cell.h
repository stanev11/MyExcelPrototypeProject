#pragma once
#include "Value.h";

class Cell
{
public:
	virtual Cell* clone() const = 0;
	virtual ~Cell() = default;

	virtual const Value& getValue() const = 0;

	virtual MyString toString() const = 0;
};

