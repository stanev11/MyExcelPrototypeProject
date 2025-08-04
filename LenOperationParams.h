#pragma once
class IParameter;

#include "OperationParams.h"

struct LenOperationParams : public OperationParams
{
	IParameter* param = nullptr;

	Operation* create() const override;
};