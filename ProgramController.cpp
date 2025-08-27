#include "ProgramController.h"

#include "fstream"

#include "TableBuilder.h"

#include "MyPropertyException.h"

#include "Value.h"

#include "FactoryCell.h"

void ProgramController::saveConfigFile() const
{
	std::ofstream ofs(this->configFile.c_str(), std::ios::binary);

	if (!ofs.is_open())
	{
		throw std::logic_error("Couldn't open file to write!");
	}

	const TableProperties& props = currentTable.getTableProps();

	int initTableRows = props.initialTableRows;
	int initTableCols = props.initialTableCols;
	int maxTableRows = props.maxTableRows;
	int maxTableCols = props.maxTableCols;
	bool autoFit = props.autoFit;
	int visibleCellSymbols = props.visibleCellSymbols;
	int initAlignment = (int)props.initialAlignment;
	bool clearConsole = props.clearConsoleAfterCommand;

	ofs.write((const char*)&initTableRows, sizeof(initTableRows));
	ofs.write((const char*)&initTableCols, sizeof(initTableCols));
	ofs.write((const char*)&maxTableRows, sizeof(maxTableRows));
	ofs.write((const char*)&maxTableCols, sizeof(maxTableCols));
	ofs.write((const char*)&autoFit, sizeof(autoFit));
	ofs.write((const char*)&visibleCellSymbols, sizeof(visibleCellSymbols));
	ofs.write((const char*)&initAlignment, sizeof(initAlignment));
	ofs.write((const char*)&clearConsole, sizeof(clearConsole));
}

void ProgramController::saveContentFile() const
{
	std::ofstream contentFile(this->contentFile.c_str(), std::ios::binary);

	if (!contentFile.is_open())
	{
		throw std::logic_error("Couldn't open file to write!");
	}

	//TODO
	

}

TableBuilder ProgramController::createConfig(const MyString& configFile)
{
	std::ifstream ifs(configFile.c_str(), std::ios::binary);

	if (!ifs.is_open())
	{
		throw std::logic_error("Couldn't open file for reading!");
	}

	this->configFile = configFile;

	TableBuilder builder;

	int initTableRows;
	int initTableCols;
	int maxTableRows;
	int maxTableCols;
	bool autoFit;
	int visibleCellSymbols;
	int initAlignment;
	bool clearConsole;

	try
	{
		ifs.read((char*)&initTableRows, sizeof(initTableRows));

		builder.setInitialTableRows(initTableRows);
	}
	catch (const std::exception&)
	{
		throw MyPropertyException("InitialTableRows", initTableRows, "Missing Property Or Invalid Value");
	}

	try
	{
		ifs.read((char*)&initTableCols, sizeof(initTableCols));

		builder.setInitialTableCols(initTableCols);
	}
	catch (const std::exception&)
	{
		throw MyPropertyException("InitialTableCols", initTableCols, "Missing Property Or Invalid Value");
	}

	try
	{
		ifs.read((char*)&maxTableRows, sizeof(maxTableRows));

		builder.setMaxTableRows(maxTableRows);
	}
	catch (const std::exception&)
	{
		throw MyPropertyException("MaxTableRows", maxTableRows, "Missing Property Or Invalid Value");
	}

	try
	{
		ifs.read((char*)&maxTableCols, sizeof(maxTableCols));

		builder.setMaxTableCols(maxTableCols);
	}
	catch (const std::exception&)
	{
		throw MyPropertyException("MaxTableCols", maxTableCols, "Missing Property Or Invalid Value");
	}

	try
	{
		ifs.read((char*)&autoFit, sizeof(autoFit));

		builder.setAutoFit(autoFit);
	}
	catch (const std::exception&)
	{
		throw MyPropertyException("AutoFit", autoFit, "Missing Property Or Invalid Value");
	}

	try
	{
		ifs.read((char*)&visibleCellSymbols, sizeof(visibleCellSymbols));

		builder.setVisibleCellSymbols(visibleCellSymbols);
	}
	catch (const std::exception&)
	{
		throw MyPropertyException("VisibleCellSymbols", visibleCellSymbols, "Missing Property Or Invalid Value");
	}

	try
	{
		ifs.read((char*)&initAlignment, sizeof(initAlignment));

		switch (initAlignment)
		{
		case 0:
			builder.setInitialAlignment(AlignmentType::left);

		case 1:
			builder.setInitialAlignment(AlignmentType::center);

		case 2:
			builder.setInitialAlignment(AlignmentType::right);
		}

	}
	catch (const std::exception&)
	{
		throw MyPropertyException("InitialAlignment", initAlignment, "Missing Property Or Invalid Value");
	}

	try
	{
		ifs.read((char*)&clearConsole, sizeof(clearConsole));

		builder.setClearConsole(clearConsole);
	}
	catch (const std::exception&)
	{
		throw MyPropertyException("ClearConsoleAfterCommand", clearConsole, "Missing Property Or Invalid Value");
	}

	return builder;
}

void ProgramController::fillTable(const MyString& contentFile)
{
	std::ifstream ifs(contentFile.c_str(), std::ios::binary);

	if (!ifs.is_open())
	{
		throw std::logic_error("Couldn't open file to read!");
	}

	int row;
	int col;

	ifs.read((char*)&row, sizeof(row));
	ifs.read((char*)&col, sizeof(col));

	CellType cellType;
	ifs.read((char*)&cellType, sizeof(int));
	//Под въпрос дали ще работи така - имплицитно кастване

	Cell* cell;

	if (cellType == CellType::SingleValueCell)
	{
		Value val;

		ValueType valueType;
		ifs.read((char*)&valueType, sizeof(int));
		//Под въпрос дали ще работи така - имплицитно кастване

		val.setType(valueType);

		if (valueType == ValueType::INT)
		{
			int value;
			ifs.read((char*)&value, sizeof(value));

			val.setIntValue(value);
		}
		else if (valueType == ValueType::DOUBLE)
		{
			double value;
			ifs.read((char*)&value, sizeof(value));

			val.setDoubleValue(value);
		}
		else if (valueType == ValueType::BOOL)
		{
			bool value;
			ifs.read((char*)&value, sizeof(value));

			val.setBoolValue(value);
		}
		else if (valueType == ValueType::STRING)
		{
			int len;
			ifs.read((char*)&len, sizeof(len));

			char* str = new char[len];
			ifs.read(str, len);

			val.setStringValue(str);

			delete[] str;
		}

		cell = FactoryCell::createCell(CellContext(val));
	}
	else if (cellType == CellType::ReferenceCell)
	{
		int refRow;
		int refCol;

		//TODO - maybe init reference cell by first init *to cell
	}
	else if (cellType == CellType::FormulaCell)
	{
		/*FormulaType formulaType;
		ifs.read((char*)&formulaType, sizeof(int));*/
		//Под въпрос дали ще работи така - имплицитно кастване

		/*if (formulaType == FormulaType::SUM)
		{

		}*/
	}

}

void ProgramController::openTable(const MyString& contentFile,const MyString& configFile)
{
	TableBuilder builder = createConfig(configFile);

	currentTable = builder.build();


}

void ProgramController::createTable(const MyString& contentFile,const MyString& configFile)
{
	this->configFile = configFile;
	this->contentFile = contentFile;

	TableBuilder builder;

	currentTable = builder.build();
}

void ProgramController::saveTable() const
{
	saveConfigFile();
	saveContentFile();
}
