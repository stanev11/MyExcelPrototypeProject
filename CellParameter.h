#pragma once
class Cell;

#include "IParameter.h"

class CellParameter : public IParameter
{
private:
	Cell* cell;
public:
	CellParameter(Cell* cell);
	IParameter* clone() const override;

	MyVector<Value> getValues() const override;
};

