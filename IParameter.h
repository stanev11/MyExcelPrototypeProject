#pragma once
class IParameter
{
public:
	virtual IParameter* clone() const = 0;
	virtual ~IParameter() = default;
};

