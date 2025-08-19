#include "Value.h"
#include "sstream"

Value::Value() : type(ValueType::EMPTY)
{
    data.sVal = "";
}

Value::Value(int value) : type(ValueType::INT)
{
    data.iVal = value;
}

Value::Value(const MyString& value) : type(ValueType::STRING)
{
    data.sVal = value;
}

Value::Value(bool value) : type(ValueType::BOOL)
{
    data.bVal = value;
}


Value::Value(double value) : type(ValueType::DOUBLE)
{
    data.dVal = value;
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

void Value::setIntValue(int val)
{
    data.iVal = val;
}

void Value::setDoubleValue(double val)
{
    data.dVal = val;
}

void Value::setBoolValue(bool val)
{
    data.bVal = val;
}

void Value::setStringValue(const MyString& val)
{
    data.sVal = val;
}

void Value::setType(ValueType type)
{
    this->type = type;
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

    switch (type)
    {
    case ValueType::EMPTY:
        return MyString();

    case ValueType::ERROR:
        return MyString("#VALUE");

    case ValueType::INT:
        s << data.iVal;
        return MyString(s.str().c_str());

    case ValueType::DOUBLE:  
        s << data.dVal;
        return MyString(s.str().c_str());

    case ValueType::BOOL:
        s << data.bVal;
        return MyString((data.bVal) ? "TRUE" : "FALSE");

    case ValueType::STRING:
        return data.sVal;
    }
}

std::ofstream& Value::saveToBinaryFile(std::ofstream& ofs) const
{
    if (!ofs.is_open())
    {
        throw std::logic_error("File couldn't be opened for writing!");
    }

    ofs.write((const char*)&type, sizeof(int));

    if (type == ValueType::BOOL)
    {
        ofs.write((const char*)&data.bVal, sizeof(bool));
    }
    else if (type == ValueType::DOUBLE)
    {
        ofs.write((const char*)&data.dVal, sizeof(double));
    }
    else if (type == ValueType::INT)
    {
        ofs.write((const char*)&data.iVal, sizeof(int));
    }
    else if (type == ValueType::STRING)
    {
        data.sVal.saveToBinaryFile(ofs);
    }

    //type EMPTY and type ERROR could be saved too - TODO
}

