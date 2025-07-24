#include "Value.h"
#include "sstream"

Value::Value() : type(ValueType::EMPTY)
{
}

Value::Value(int value) : type(ValueType::INT)
{
    data.iVal = value;
}

Value::Value(bool value) : type(ValueType::BOOL)
{
    data.bVal = value;
}

Value::Value(double value) : type(ValueType::DOUBLE)
{
    data.dVal = value;
}

Value::Value(const MyString& value) : type(ValueType::STRING)
{
    data.sVal = value;
}

bool Value::isEmpty() const
{
    return type==ValueType::EMPTY;
}

ValueType Value::getType() const
{
    return type;
}

int Value::getIntValue() const
{
    if (type == ValueType::INT) return data.iVal;

    //throw ? - TODO
}

double Value::getDoubleValue() const
{
    if (type == ValueType::DOUBLE) return data.dVal;
}

bool Value::getBoolValue() const
{
    if (type == ValueType::BOOL) return data.bVal;
}

const MyString& Value::getStringValue() const
{
    if (type == ValueType::STRING) return data.sVal;
}

void Value::releaseValue()
{
    type = ValueType::EMPTY;
}

void Value::setErrorState()
{
    type = ValueType::ERROR;
}

MyString Value::toString() const
{
    std::ostringstream s;
    s << data.dVal;

    switch (type)
    {
    case ValueType::EMPTY:
        return MyString();

    case ValueType::ERROR:
        return MyString("#VALUE");

    case ValueType::INT:
        return MyString(""+data.iVal);

    case ValueType::DOUBLE:  
        return MyString(s.str().c_str());

    case ValueType::BOOL:
        return MyString(""+data.bVal);

    case ValueType::STRING:
        return data.sVal;
    }
}

