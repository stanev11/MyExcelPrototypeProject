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
#include "CountOperationParams.h"

#include "ValueParameter.h"
#include "CellParameter.h"

#include "TableBuilder.h"
#include "TableView.h"

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
	

	Cell* cell1 = new SingleValueCell(MyString("okayles"));
	Cell* cell2 = new ReferenceCell(cell1);
	Cell* cell3 = new SingleValueCell(12);

	table.insertAt(1,1,cell1);
	table.insertAt(3,1,cell2);
	table.insertAt(1, 2, 5);
	table.insertAt(1, 4, MyString("abcde"));


	CellContext ctx;
	CountOperationParams par(RangeParameter(cell1,cell2,&table));
	//par.params.addObject(ValueParameter(12));
	//par.params.addObject(ValueParameter(90));

	ctx.operation = FactoryOperation::createOperation(par);

	table.insertAt(0, 0, ctx);

	//table.deleteAt(3, 1); - NOT WORKING

	/*CellContext ctx;
	ctx.value = 32;
	table.insertAt(*cell1, ctx);*/

	TableView view(table);
	view.render();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
