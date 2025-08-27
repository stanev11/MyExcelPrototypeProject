#pragma once
#include "MyVector.hpp"
#include "Value.h"
#include "ParameterType.h"

class IParameter
{
private:
	ParameterType type;
public:
	IParameter(const ParameterType& type);

	virtual IParameter* clone() const = 0;
	virtual ~IParameter() = default;

	virtual MyVector<Value> getValues() const = 0;

	const ParameterType& getType() const; 

	virtual std::ofstream& saveToBinaryFile(std::ofstream& ofs) const;
};

