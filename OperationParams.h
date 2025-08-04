#pragma once
class Operation;

struct OperationParams
{
	virtual ~OperationParams() = default;
	virtual Operation* create() const = 0;
};