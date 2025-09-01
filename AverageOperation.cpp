#include "AverageOperation.h"
#include "CellParameter.h"

#include "FormulaCell.h"


AverageOperation::AverageOperation() : Operation(FormulaType::AVERAGE)
{
}

AverageOperation::AverageOperation(const HeterogeneousContainer<IParameter>& params) : params(params),Operation(FormulaType::AVERAGE)
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

bool AverageOperation::hasCircularReference(const Cell& cell) const
{
    int row = cell.getRow();
    int col = cell.getCol();

    for (size_t i = 0; i < params.getSize(); i++)
    {
        const IParameter* param = params[i];

        if (param->getType() == ParameterType::CellParameter)
        {
            const CellParameter* cellParam = dynamic_cast<const CellParameter*>(param);

            if (cellParam->getCell().getRow() == row && cellParam->getCell().getCol() == col)
            {
                return true;
            }
        }
    }

    return false;
}

std::ofstream& AverageOperation::saveToBinaryFile(std::ofstream& ofs) const
{
    Operation::saveToBinaryFile(ofs);

    int size = params.getSize();
    ofs.write((const char*)&size, sizeof(int));

    for (size_t i = 0; i < size; i++)
    {
        params[i]->saveToBinaryFile(ofs);
    }

    return ofs;
}
