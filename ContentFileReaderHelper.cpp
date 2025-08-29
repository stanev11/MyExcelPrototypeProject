#include "ContentFileReaderHelper.h"
#include "Table.h"

RangeParameter ContentFileReaderHelper::readRangeParameter(std::ifstream& ifs,Table* table)
{
	int startRow;
	int startCol;

	ifs.read((char*)&startRow, sizeof(startRow));
	ifs.read((char*)&startCol, sizeof(startCol));

	int endRow;
	int endCol;

	ifs.read((char*)&endRow, sizeof(endRow));
	ifs.read((char*)&endCol, sizeof(endCol));

	//risky

	Cell& start = table->at(startRow, startCol);
	Cell& end = table->at(endRow, endCol);

	return RangeParameter(&start, &end, table);
}

Value ContentFileReaderHelper::readValue(std::ifstream& ifs)
{
	Value val;

	ValueType valueType;
	ifs.read((char*)&valueType, sizeof(int));

	val.setType(valueType);

	if ((ValueType)valueType == ValueType::BOOL)
	{
		bool bVal;
		ifs.read((char*)&bVal, sizeof(bool));

		val.setBoolValue(bVal);
	}
	else if ((ValueType)valueType == ValueType::DOUBLE)
	{
		double dVal;
		ifs.read((char*)&dVal, sizeof(double));

		val.setDoubleValue(dVal);
	}
	else if ((ValueType)valueType == ValueType::INT)
	{
		int iVal;
		ifs.read((char*)&iVal, sizeof(int));

		val.setIntValue(iVal);
	}
	else if ((ValueType)valueType == ValueType::STRING)
	{
		int size;
		ifs.read((char*)&size, sizeof(size));

		char* str = new char[size+1];
		ifs.read(str, size);
		str[size] = '\0';

		val.setStringValue(str);

		delete[] str;
	}

	return val;
}

CellParameter ContentFileReaderHelper::readCellParameter(std::ifstream& ifs,Table* table)
{
	int row;
	int col;

	ifs.read((char*)&row, sizeof(row));
	ifs.read((char*)&col, sizeof(col));

	//adding that param may be trouble if cell param isnt initiated

	Cell& cell = table->at(row, col);

	return CellParameter(&cell);
}
