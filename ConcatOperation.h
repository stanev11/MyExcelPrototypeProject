#pragma once
#include "Operation.h"
#include "RangeParameter.h"

class ConcatOperation : public Operation
{
private:
	RangeParameter range;
	char delimiter;
public:
	ConcatOperation(const RangeParameter& range, char delim);

	Operation* clone() const override;
	Value execute() override;

	bool hasCircularReference(const Cell& cell) const override;

	std::ofstream& saveToBinaryFile(std::ofstream& ofs) const override;
};

