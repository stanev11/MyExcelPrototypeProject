#include "SubstrOperation.h"

SubstrOperation::SubstrOperation(IParameter* parameter, int startIndex, int len) : parameter(parameter),startIndex(startIndex),length(len)
{
    if (parameter == nullptr)
    {
        throw std::invalid_argument("Nullptr!");
    }
}

Operation* SubstrOperation::clone() const
{
    return new SubstrOperation(*this);
}

Value SubstrOperation::execute()
{
    const MyVector<Value>& values = parameter->getValues();

    Value v;
    v.setErrorState();

    if (values.getSize() > 1)
    {
        return v;
    }

    Value value = values[0];

    int valueLen = 0;

    if (value.getType() == ValueType::STRING)
    {
        valueLen = value.getStringValue().length();
    }
    else
    {
        return v;
    }

    if (startIndex >= valueLen || length>valueLen || startIndex+length>valueLen)
    {
        return v;
    }

    MyString res(value.getStringValue());

    return Value(res.substr(startIndex, startIndex + length-1));

    //TODO - bad 

}