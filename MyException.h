#pragma once

#include "MyString.h"

class MyException : public std::exception
{
protected:
	MyString message;
public:
	MyException(const MyString& message);

	virtual ~MyException() = default;
};

