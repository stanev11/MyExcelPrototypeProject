#pragma once
#include "Cell.h"

class ReferenceCell : public Cell
{
private:
	Cell* to;
public:
	ReferenceCell();
	ReferenceCell(Cell* to);

	Cell* clone() const override;
	void release();

	const Value& getValue() const override;
	MyString toString() const override;

	std::ofstream& saveToBinaryFile(std::ofstream& ofs) const override;
};

