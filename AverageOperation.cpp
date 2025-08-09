#include "AverageOperation.h"
#include "CellParameter.h"

AverageOperation::AverageOperation()
{
}

AverageOperation::AverageOperation(const HeterogeneousContainer<IParameter>& params) : params(params)
{
}

Operation* AverageOperation::clone() const
{
    return new AverageOperation(*this);
}

Value AverageOperation::execute()
{
    //TODO
    MyVector<Value> vec;

    double result = 0;
    bool flag = false;
    size_t size = params.getSize();

    for (size_t i = 0; i < size; i++)
    {
        vec = params[i]->getValues();

        for (size_t j = 0; j < vec.getSize(); j++)
        {
            if (vec[j].getType() == ValueType::INT)
            {
                result += vec[j].getIntValue();
                flag = true;
            }
            else if (vec[j].getType() == ValueType::DOUBLE)
            {
                result += vec[j].getDoubleValue();
                flag = true;
            }
            else if (vec[j].getType() == ValueType::BOOL)
            {
                result += (vec[j].getBoolValue()) ? 1 : 0;
                flag = true;
            }
        }
    }

    if (!flag)
    {
        Value v;
        v.setErrorState();
        return v;
    }

    return Value(result / size);

    //! DUPLICATING CODE WITH SUM OPERATION - TODO !
}
