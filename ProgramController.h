#pragma once 

class TableBuilder;
#include "MyString.h"
#include "Table.h"

class ProgramController
{
private:
	ProgramController() = default;

	Table currentTable;
	
	void saveConfigFile(const MyString& configFile) const;
	void saveContentFile(const MyString& contentFile) const;

	void saveCellsToFile(const HeterogeneousContainer<Cell>& cells, std::ofstream& ofs) const;

	TableBuilder createConfig(const MyString& configFile);
	void fillTable(const MyString& contentFile);

public:
	static ProgramController getInstance();

	Table& openTable(const MyString& contentFile,const MyString& configFile);
	void createTable(const MyString& contentFile,const MyString& configFile);

	void saveTable(const MyString& contentFile,const MyString& configFile) const;

};

