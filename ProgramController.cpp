#include "ProgramController.h"

#include "fstream"

#include "TableBuilder.h"

#include "MyPropertyException.h"

#include "Value.h"

#include "FactoryCell.h"

#include "ValueParameter.h"

#include "ContentFileReaderHelper.h"

#include "CellParameter.h"

#include "FactoryOperation.h"
#include "SumOperationParams.h"
#include "AverageOperationParams.h"

#include "MinOperationParams.h"
#include "MaxOperationParams.h"


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
	
	int currentRows = currentTable.getRowsCount();
	int currentCols = currentTable.getColsCount();

	//contentFile.write((const char*)&currentRows, sizeof(currentRows));
	//contentFile.write((const char*)&currentCols, sizeof(currentCols));

	for (size_t i = 0; i < currentRows; i++)
	{
		for (size_t j = 0; j < currentCols; j++)
		{
			const Cell& currentCell = currentTable.at(i, j);

			currentCell.saveToBinaryFile(contentFile);
		}
	}
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
		Value val = ContentFileReaderHelper::readValue(ifs);
		
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
		FormulaType formulaType;
		ifs.read((char*)&formulaType, sizeof(int));
		//Под въпрос дали ще работи така - имплицитно кастване

		Operation* op;

		if (formulaType == FormulaType::SUM || formulaType==FormulaType::AVERAGE)
		{
			int paramsSize;
			ifs.read((char*)&paramsSize, sizeof(paramsSize));

			HeterogeneousContainer<IParameter> params;

			for (size_t i = 0; i < paramsSize; i++)
			{
				ParameterType paramType;
				ifs.read((char*)&paramType, sizeof(int));

					if (paramType == ParameterType::ValueParameter)
					{
						params.addObject(new ValueParameter(ContentFileReaderHelper::readValue(ifs)));
					}
					else if (paramType == ParameterType::CellParameter)
					{
						params.addObject(ContentFileReaderHelper::readCellParameter(ifs,&currentTable));
					}
					else if (paramType == ParameterType::RangeParameter)
					{
						params.addObject(ContentFileReaderHelper::readRangeParameter(ifs,&currentTable));
					}
			}
			
			if (formulaType == FormulaType::SUM)
			{
				SumOperationParams sumParams(params);

				op = FactoryOperation::createOperation(sumParams);
			}
			else if (formulaType == FormulaType::AVERAGE)
			{
				AverageOprationParams avgParams(params);

				op = FactoryOperation::createOperation(avgParams);
			}
		}
		else if (formulaType == FormulaType::MIN)
		{
			MinOperationParams minParams(ContentFileReaderHelper::readRangeParameter(ifs,&currentTable));

			op = FactoryOperation::createOperation(minParams);
		}
		else if (formulaType == FormulaType::MAX)
		{
			MaxOperationParams maxParams(ContentFileReaderHelper::readRangeParameter(ifs,&currentTable));

			op = FactoryOperation::createOperation(maxParams);
		}

		cell = FactoryCell::createCell(CellContext(op));

		//may not work? - TBD
		currentTable.setCell(row, col, cell);
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
