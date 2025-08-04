#pragma once
class IParameter;

#include "OperationParams.h"

struct SubstrOperationParams : public OperationParams
{
	IParameter* parameter;
	int startIndex;
	int length;

	Operation* create() const override;
};