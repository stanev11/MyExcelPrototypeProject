#include "LenOperation.h"

#include "Cell.h"

#include "CellParameter.h"

LenOperation::LenOperation(IParameter* parameter) : parameter(parameter),Operation(FormulaType::LEN)
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

bool LenOperation::hasCircularReference(const Cell& cell) const
{
    if (parameter->getType() == ParameterType::CellParameter)
    {
        const CellParameter* cellParam = dynamic_cast<const CellParameter*>(parameter);

        if (cellParam->getCell().getRow() == cell.getRow() && cellParam->getCell().getCol() == cell.getCol())
        {
            return true;
        }
    }

    return false;
}

