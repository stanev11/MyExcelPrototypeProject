#include "ProgramController.h"

#include "fstream"

#include "TableBuilder.h"

#include "MyPropertyException.h"

void ProgramController::openTable(const MyString& configFile)
{
	std::ifstream ifs(configFile.c_str(),std::ios::binary);

	if (!ifs.is_open())
	{
		throw std::logic_error("Couldn't open file for reading!");
	}

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
		case 0 : 
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

	currentTable = builder.build();
}
