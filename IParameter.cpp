#include "IParameter.h"

IParameter::IParameter(const ParameterType& type) : type(type)
{
}

const ParameterType& IParameter::getType() const
{
	return type;
}

std::ofstream& IParameter::saveToBinaryFile(std::ofstream& ofs) const
{
	if (!ofs.is_open())
	{
		throw std::logic_error("Couldn't open file to write!");
	}

	ofs.write((const char*)&type, sizeof(int));

	return ofs;
}
