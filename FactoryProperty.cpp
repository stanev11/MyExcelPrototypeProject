#include "FactoryProperty.h"

InitialTableRows* FactoryProperty::createInitialTableRows(int value)
{
    return new InitialTableRows(value);
}

InitialTableCols* FactoryProperty::createInitialTableCols(int value)
{
    return new InitialTableCols(value);
}

MaxTableRows* FactoryProperty::createMaxTableRows(int value)
{
    return new MaxTableRows(value);
}

MaxTableCols* FactoryProperty::createMaxTableCols(int value)
{
    return new MaxTableCols(value);
}

InitialAlignment* FactoryProperty::createInitialAlignment(AlignmentType alignment)
{
    return new InitialAlignment(alignment);
}

AutoFit* FactoryProperty::createAutoFit(bool value)
{
    return new AutoFit(value);
}

ClearConsoleAfterCommand* FactoryProperty::createClearConsole(bool value)
{
    return new ClearConsoleAfterCommand(value);
}

VisibleCellSymbols* FactoryProperty::createVisibleCellSymbols(int value)
{
    return new VisibleCellSymbols(value);
}

Property* FactoryProperty::createProperty(PropertyType type, bool value)
{
    switch (type)
    {

    case PropertyType::AutoFit:
        return createAutoFit(value);

    case PropertyType::ClearConsoleAfterCommand:
        return createClearConsole(value);

    }

    //throw invalid arguments - TODO
}

Property* FactoryProperty::createProperty(PropertyType type, int value)
{
    switch (type)
    {

    case PropertyType::InitialTableRows:
        return createInitialTableRows(value);

    case PropertyType::InitialTableCols:
        return createInitialTableCols(value);

    case PropertyType::MaxTableRows:
        return createMaxTableRows(value);

    case PropertyType::MaxTableCols:
        return createMaxTableCols(value);

    case PropertyType::VisibleCellSymbols:
        return createVisibleCellSymbols(value);

    }

    //throw exception - TODO
}

Property* FactoryProperty::createProperty(PropertyType type, AlignmentType alignment)
{
    switch (type)
    {

    case PropertyType::InitialAlignment:
        return createInitialAlignment(alignment);

    }

    //throw exception - TODO
}
