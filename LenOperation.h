#pragma once
#include "Operation.h"

class LenOperation : public Operation
{
private:
	IParameter* parameter = nullptr;
public:
	LenOperation(IParameter* parameter);

	Operation* clone() const override;
	Value execute() override;

	bool hasCircularReference(const Cell& cell) const override;

	std::ofstream& saveToBinaryFile(std::ofstream& ofs) const override;
};

