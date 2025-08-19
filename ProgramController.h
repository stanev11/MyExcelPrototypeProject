#pragma once 

class TableBuilder;
#include "MyString.h"
#include "Table.h"

class ProgramController
{
private:

	MyString contentFile;
	MyString configFile;

	Table currentTable;
	
	void saveConfigFile() const;
	void saveContentFile() const;

	TableBuilder createConfig(const MyString& configFile);
	void fillTable(const MyString& contentFile);

public:
	void openTable(const MyString& contentFile,const MyString& configFile);
	void createTable(const MyString& contentFile,const MyString& configFile);

	void saveTable() const;

};

