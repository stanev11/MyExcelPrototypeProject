#include "TableView.h"
#include "sstream"
#include "iomanip"

void TableView::clearConsole() const
{
	system("cls");
}

MyString TableView::formatCellContent(const Cell& cell, int width, AlignmentType alignment) const
{
	std::stringstream ss;

	MyString content = cell.toString();

	const TableProperties props = table.getTableProps();

	if (props.visibleCellSymbols > 0 && content.length() > props.visibleCellSymbols)
	{
		content = content.substr(0, props.visibleCellSymbols - 1);
	}

	int padding = width - content.length();

	if (padding < 0) padding = 1;

	switch (alignment)
	{
	case AlignmentType::left:

		ss << std::left << std::setw(width)<<content;
		break;

	case AlignmentType::center:

		ss << std::setw(padding / 2 + content.length()) << content;
		ss << std::setw(padding - padding / 2)<<" ";
		break;

	case AlignmentType::right:

		ss << std::right << std::setw(width) << content;
		break;

	}

	return ss.str().c_str();
}

TableView::TableView(const Table& table) : table(table)
{
}

void TableView::render()
{
	const TableProperties& props = table.getTableProps();

	if (props.clearConsoleAfterCommand)
	{
		clearConsole();
	}

	const int cellWidth = props.visibleCellSymbols;
	const int padding = 1;
	const char seperator = '|';

	for (size_t i = 1; i <= table.getRowsCount(); i++)
	{
		for (size_t j = 1; j <= table.getColsCount(); j++)
		{
			const Cell& cell = table.at(i, j);
			
			MyString formatted = formatCellContent(cell, cellWidth, props.initialAlignment);

			std::cout << formatted << seperator;
		}
		std::cout << std::endl;
	}

}
