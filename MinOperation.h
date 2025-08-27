#pragma once
#include "Operation.h"
#include "RangeParameter.h"

class MinOperation : public Operation
{
private:
	RangeParameter range;
public:

	MinOperation(const RangeParameter& range);

	Operation* clone() const override;
	Value execute() override;

	bool hasCircularReference(const Cell& cell) const override;

	std::ofstream& saveToBinaryFile(std::ofstream& ofs) const override;
};

