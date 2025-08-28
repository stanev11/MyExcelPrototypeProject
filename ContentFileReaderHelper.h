#pragma once
#include "RangeParameter.h"
#include "ValueParameter.h"
#include "CellParameter.h"

class ContentFileReaderHelper
{
public:
	static RangeParameter readRangeParameter(std::ifstream& ifs,Table* table);
	static Value readValue(std::ifstream& ifs);
	static CellParameter readCellParameter(std::ifstream& ifs,Table* table);
};

