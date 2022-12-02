#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
using namespace std;


class COLLUMN
{
public:
	string colName;
	int size;
	string type;
	char** elemente;
	int lines;
	const int maxlenght = 100;

	COLLUMN()
	{
		this->size = 0;
		this->colName = ' ';
		this->type = ' ';
		this->lines = 0;
		this->elemente = NULL;

	}

	COLLUMN(char* colName, int size, const char* type, char** elemente, int lines)
	{

		this->colName = colName;
		

		this->type = type;

		if (this->elemente == NULL)
		{
			this->lines = lines;

			this->elemente = new char* [lines * sizeof(char*)];
			for (int i = 0; i < lines; i++)
				this->elemente[i] = new char(maxlenght * sizeof(char));
		}
	}

	void setSize(int size)
	{
		this->size = size;
	}

	void setColName(string colName)
	{
		this->colName = colName;
		
	}

	void setType(string type)
	{
		this->type = type;
	}

	void setElemente(int lines, const char* value)
	{
		if (this->elemente == NULL)
		{
			this->lines = lines;

			this->elemente = new char* [lines * sizeof(char*)];
			for(int i = 0; i < lines; i++)
				this->elemente[i] = new char(maxlenght * sizeof(char));
		}
		for (int i = 0; i < lines; i++)
		{
			strcpy_s(this->elemente[i], strlen(value + 1), value);
		}
	}

	void setLines()
	{
		this->lines = lines + 1;

	}

	//COLLUMN& operator=(const COLLUMN& c)
	//{
	//	if (this  != &c)
	//	{
	//		this->colName = new char[strlen(c.colName)];
	//		strcpy_s(this->colName, strlen(c.colName) + 1, c.colName);

	//		type = new char[strlen(c.type)];
	//		strcpy_s(this->type, strlen(c.type) + 1,c.type);

	//		if (this->elemente == NULL)
	//		{
	//			this->lines = c.lines;

	//			this->elemente = new char* [c.lines * sizeof(char*)];
	//			for (int i = 0; i < lines; i++)
	//				this->elemente[i] = new char(c.maxlenght * sizeof(char));
	//		}
	//		
	//	
	//	}
	//	return *this;
	//}

	~COLLUMN() {
		

	}

};


class TABLE:COLLUMN
{
public:
	string tableName;
	vector<COLLUMN> coloana;
	int nrofCollumns;

	TABLE()
	{
		this->tableName = ' ';
		this->nrofCollumns = 0;
		
		
	}

	TABLE(string tableName, int nrofCollumns)
	{
		this->tableName = tableName;
		

		this->nrofCollumns = nrofCollumns;
		
	}
	void setTabelName(string tableName)
	{
		this->tableName = tableName;
	}

	void addColoane()
	{
		this->nrofCollumns = nrofCollumns+1;

	}

	

 string getTableName()
	{
		return this->tableName;
	}

	~TABLE()
	{
	

	}

};


class ALLTables {
public:
	vector<TABLE> tabele;
	int nrOfTables;

	ALLTables()
	{
		this->nrOfTables = 0;

	}

	bool tableVerification(string numeTabel)
	{
		int ok = 0;
		for (int i = 0; i < nrOfTables; i++)
		{
			if (tabele[i].tableName== numeTabel)
				ok++;

		}
		if (ok == 0)
			return true;
		else
			return false;
	}

	void addTables()
	{
		this->nrOfTables = nrOfTables + 1;
	}
};



class CreateTable:ALLTables{
	
public:
	


	
};

//class for the Drop Table command
class DropTable {



};
//class for Display Table
class DisplayTable {

};

class DropIndex {

};

class CreateIndex {

};

char* lower(char comanda[])
{
	for (int i = 0; comanda[i] != NULL; i++)
	{
		comanda[i] = tolower(comanda[i]);
	}

	return comanda;
}

void findMyCommand(char* command, ALLTables &database)
{
	string s;
	char* next_token;
	char* secCommand = strtok_s(command," ", &next_token);
	//Create - command
	if (strcmp(lower(secCommand), "create") == 0)
	{
		secCommand = strtok_s(NULL, " ", &next_token);

		if (strcmp(lower(secCommand), "table") == 0)
		{
			//the table's name
			secCommand = strtok_s(NULL, " ", &next_token);
			//verify if the table's name is not null
			if (secCommand != NULL)
			{
				//transform the char into a string
				s = lower(secCommand);
				//verify if the table's name is not already in the database
				if (database.tableVerification(secCommand))
				{
					//we make a local object of TABLE class
					TABLE tabel1;
					tabel1.setTabelName(s);

					//we create a local object of COLLUMN class
					COLLUMN coloana1;
					//here we must introuce at least 1 collumn to the table
				
					
					//column name
					secCommand = strtok_s(NULL, " ,()", &next_token);
					s = lower(secCommand);

					coloana1.setColName(s);//setter for collumn name

					//type of collumn
					secCommand = strtok_s(NULL, " ,()", &next_token);

					s = lower(secCommand);
					coloana1.setType(s);//setter for type

					//size
					secCommand = strtok_s(NULL, " ,()", &next_token);
					int x = atoi(secCommand);
					
					coloana1.setSize(x);//setter for size

					tabel1.coloana.push_back(coloana1);
					tabel1.addColoane();
					database.tabele.push_back(tabel1);
					database.addTables();

				}
				else
				{
					cout << "The table's name is already in the database" << endl;
					
					//the table's name is already in the database
				}
				
				

			}
		}
		else if (strcmp(lower(secCommand), "index") == 0)
		{

		}
		//wrong input case
		else
		{

		}
	}//drop - command
	else if (strcmp(lower(secCommand), "drop") == 0)
		{
			secCommand = strtok_s(NULL, " ", &next_token);

			if (strcmp(lower(secCommand), "table")==0)
			{

			}
			else if (strcmp(lower(secCommand), "index") == 0)
				{
				//index name
				secCommand = strtok_s(NULL, " ", &next_token);

				}
			//wrong input case
				else {

				}

		}
	//display - command
	else if (strcmp(lower(secCommand), "display") == 0)
	{
		secCommand = strtok_s(NULL, " ", &next_token);
		if (strcmp(lower(secCommand), "table") == 0)
		{
			//table name
			secCommand = strtok_s(NULL, " ", &next_token);

		}
		//wrong input case
		else
		{

		}

	}
	else
		//wrong input case
	{

	}

}