// MyExcelPrototypeProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FactoryProperty.h"
#include "FactoryCell.h"
#include "FactoryOperation.h"

#include "SumOperationParams.h"
#include "AverageOperationParams.h"
#include "SubstrOperationParams.h"
#include "LenOperationParams.h"
#include "MinOperationParams.h"
#include "MaxOperationParams.h"
#include "CountOperationParams.h"

#include "ValueParameter.h"
#include "CellParameter.h"

#include "TableBuilder.h"
#include "TableView.h"
#include "Table.h"

int main()
{
	TableBuilder builder;

	builder.setInitialTableRows(5)
		.setInitialTableCols(5)
		.setInitialAlignment(AlignmentType::left)
		.setAutoFit(false)
		.setClearConsole(true)
		.setVisibleCellSymbols(6);

	Table table = builder.build();
	

	Cell* cell1 = FactoryCell::createCell(CellContext(11.35));
	Cell* cell2 = FactoryCell::createCell(CellContext(11.38));
	Cell* cell3 = FactoryCell::createCell(CellContext(MyString("Yasen")));

	table.insertAt(1,1,cell1);
	table.insertAt(1,2,cell2);
	table.insertAt(2, 3, cell3);
	table.insertAt(1, 4, MyString("abcde"));

	//table.deleteAt(3, 1); - NOT WORKING

	MinOperationParams par(RangeParameter(cell1, cell3, &table));
	Operation* op = FactoryOperation::createOperation(par);
	
	Cell* cell4 = FactoryCell::createCell(CellContext(op));

	table.insertAt(2, 4, cell4);

	TableView view(table);
	view.render();
}

