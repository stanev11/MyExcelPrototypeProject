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

#include "ProgramController.h"

int main()
{
	ProgramController controller = ProgramController::getInstance();

	//TableBuilder builder;

	//builder.setInitialTableRows(5)
	//	.setInitialTableCols(5)
	//	.setInitialAlignment(AlignmentType::left)
	//	.setAutoFit(false)
	//	.setClearConsole(true)
	//	.setVisibleCellSymbols(6);

	//Table table = builder.build();

	//Cell* cell1 = FactoryCell::createCell(CellContext(11.35));
	//Cell* cell2 = FactoryCell::createCell(CellContext(11.38));
	//Cell* cell3 = FactoryCell::createCell(CellContext(MyString("Yasen")));

	//table.insertAt(1,1,cell1);
	//table.insertAt(1,2,cell2);
	//table.insertAt(2, 3, cell3);
	//table.insertAt(1, 4, MyString("abcde"));

	////table.deleteAt(3, 1); - NOT WORKING


	//AverageOprationParams par;
	//par.params.addObject(new CellParameter(cell1));
	//par.params.addObject(new CellParameter(cell2));

	//Operation* op = FactoryOperation::createOperation(par);

	//Cell* cell4 = FactoryCell::createCell(CellContext(op));

	//table.insertAt(1, 3, cell4);

	//table.setCell(1, 3,new EmptyCell());

	Table& table = controller.openTable("contentFile.txt", "configFile.txt");

//    table.insertAt(3, 2, Value(MyString("Iva")));

	//table.insertAt(4, 1, new ReferenceCell(&table.at(2,3)));

	//table.insertAt(2, 3,MyString("What?"));

	//SumOperationParams params;
	//params.params.addObject(new CellParameter(&table.at(1, 1)));

	//params.params.addObject(new ValueParameter(12));

	//params.params.addObject(new CellParameter(&table.at(1, 2)));

	//table.insertAt(4, 2, FactoryCell::createCell(params.create()));

	TableView view(table);
	view.render();

	controller.setCurrentTable(table);

	controller.saveTable("contentFile.txt", "configFile.txt");

	Cell* c = new ReferenceCell();
}

