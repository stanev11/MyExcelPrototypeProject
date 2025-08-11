#pragma once

#include "MyException.h"
#include "PropertyType.h"

class MyPropertyException : public MyException
{
protected:
	MyString type;
	int value;
public:
	MyPropertyException(const MyString& type, int value, const MyString& message);

	const char* what() const override;
};

