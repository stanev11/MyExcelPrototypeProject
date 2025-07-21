#include "AutoFit.h"

AutoFit::AutoFit() : AutoFit(0)
{
}

AutoFit::AutoFit(bool value) : Property(PropertyType::AutoFit),value(value)
{
}

Property* AutoFit::clone() const
{
    return new AutoFit(*this);
}
