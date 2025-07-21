#include "ClearConsoleAfterCommand.h"

ClearConsoleAfterCommand::ClearConsoleAfterCommand() : ClearConsoleAfterCommand(0)
{
}

ClearConsoleAfterCommand::ClearConsoleAfterCommand(bool value) : Property(PropertyType::ClearConsoleAfterCommand),value(value)
{
}

Property* ClearConsoleAfterCommand::clone() const
{
    return new ClearConsoleAfterCommand(*this);
}
