#pragma once
#include "MyString.h"
#include "fstream"

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

	void setIntValue(int val);
	void setDoubleValue(double val);
	void setBoolValue(bool val);
	void setStringValue(const MyString& val);
	void setType(ValueType type);

	void releaseValue();
	void setErrorState();
	
	MyString toString() const;

	std::ofstream& saveToBinaryFile(std::ofstream& ofs) const;
};
