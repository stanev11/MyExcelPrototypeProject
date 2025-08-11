#include "MyPropertyException.h"

#include "sstream"

MyPropertyException::MyPropertyException(const MyString& type, int value, const MyString& message) : type(type),value(value),MyException(message)
{

}

const char* MyPropertyException::what() const
{
	MyString what("ABORTING! ");

	what += type+ " : " ;

	std::ostringstream ss;

	ss << value;

	what += ss.str().c_str();

	what += " - " + message;

	return what.c_str();
}
