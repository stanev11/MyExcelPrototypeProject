#include "LenOperation.h"

LenOperation::LenOperation(IParameter* parameter) : parameter(parameter)
{
    if (parameter==nullptr)
    {
        throw std::invalid_argument("Nullptr!");
    }
}

Operation* LenOperation::clone() const
{
    return new LenOperation(*this);
}

Value LenOperation::execute()
{
   const MyVector<Value>& values = parameter->getValues();

   if (values.getSize() > 1)
   {
       Value v;
       v.setErrorState();
       return v;
   }

   MyString str = values[0].toString();

   int len = str.length();
   
   return Value(len);
}

