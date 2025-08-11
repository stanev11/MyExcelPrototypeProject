#pragma once 

#include "MyString.h"
#include "Table.h"

class ProgramController
{
private:
	MyString currentFile;
	Table currentTable;

public:
	void openTable(const MyString& configFile);
	void createTable(const MyString& configFile);

	void saveTable() const;

};

