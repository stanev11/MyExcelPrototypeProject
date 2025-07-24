#pragma once
#include "AlignmentType.h"

struct TableProperties
{
	int initialTableRows = 0;
	int initialTableCols = 0;
	int maxTableRows = 0;
	int maxTableCols = 0;
	bool autoFit = true;
	int visibleCellSymbols = 0;

	AlignmentType initialAlignment;

	bool clearConsoleAfterCommand = true;
};