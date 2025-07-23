#include "Value.h"

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

