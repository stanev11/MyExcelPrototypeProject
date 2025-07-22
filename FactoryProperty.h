#pragma once
#include "Property.h"

#include "InitialTableRows.h"
#include "InitialTableCols.h"
#include "MaxTableRows.h"
#include "MaxTableCols.h"
#include "InitialAlignment.h"
#include "AutoFit.h"
#include "ClearConsoleAfterCommand.h"
#include "VisibleCellSymbols.h"

class FactoryProperty
{
private:

	static InitialTableRows* createInitialTableRows(int value);
	static InitialTableCols* createInitialTableCols(int value);
	static MaxTableRows* createMaxTableRows(int value);
	static MaxTableCols* createMaxTableCols(int value);
	static InitialAlignment* createInitialAlignment(AlignmentType alignment);
	static AutoFit* createAutoFit(bool value);
	static ClearConsoleAfterCommand* createClearConsole(bool value);
	static VisibleCellSymbols* createVisibleCellSymbols(int value);

public:
	static Property* createProperty(PropertyType type,bool value);
	static Property* createProperty(PropertyType type, int value);
	static Property* createProperty(PropertyType type, AlignmentType alignment);
};

