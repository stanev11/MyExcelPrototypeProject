#pragma once
#include "MyString.h"

enum class ValueType
{
	EMPTY,
	ERROR,
	INT,
	DOUBLE,
	BOOL,
	STRING
};

class Value
{
private:
	ValueType type;
	struct {
		int iVal;
		double dVal;
		bool bVal;
		MyString sVal;

	} data;

public:
	Value();
	Value(int value);
	Value(double value);
	Value(const MyString& value);
	Value(bool value);

	bool isEmpty() const;
	ValueType getType() const;

	int getIntValue() const;
	double getDoubleValue() const;
	bool getBoolValue() const;
	const MyString& getStringValue() const;

	void releaseValue();
	void setErrorState();
	
	MyString toString() const;
};
