#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
using namespace std;
class ELEMENTE {

public:
	string value;

	ELEMENTE()
	{
		this->value = ' ';
	}

	void addElemente(string e)
	{
		this->value = e;

	}

	ELEMENTE& operator=(const ELEMENTE& e)
	{
		if (this != &e)
		{
			this->value = e.value;
		}
		return *this;

	
	}
	

	~ELEMENTE()
	{

	}
};

class COLLUMN
{
public:
	string colName;
	int size;
	string type;
	ELEMENTE* elemente;
	int nr_elemente;

	COLLUMN()
	{
		this->size = 0;
		this->colName = ' ';
		this->type = ' ';
		this->elemente = new ELEMENTE[10];
		this->nr_elemente = 0;

	}

	COLLUMN(string colName, int size, string type)
	{

		this->colName = colName;
		this->type = type;
		this->size = size;
		
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

	void addELEMENTE(ELEMENTE &element, int nr_elemente)
	{
		this->elemente[nr_elemente] = element;

	}

	void addNrElemente()
	{
		this->nr_elemente = nr_elemente + 1;
	}

	COLLUMN& operator=(const COLLUMN& c)
	{
		if (this  != &c)
		{
			this->colName = c.colName;
            this->type = c.type;
			this->size = c.size;
			this->nr_elemente = c.nr_elemente;
			for (int i = 0; i < 10; i++)
			{
				this->elemente[i] = c.elemente[i];
			}
		
		}
		return *this;
	}

	~COLLUMN() {
		
	}

};


class TABLE :COLLUMN
{
public:
	string tableName;
	COLLUMN* coloana;
	int nrofCollumns;

	TABLE()
	{
		this->tableName = ' ';
		this->nrofCollumns = 0;
		this->coloana = new COLLUMN[10];
		
	
		
	}
	

	void addCOLLUMNS(COLLUMN &coloana_noua,int nrofCollumns)
	{
		
			this->coloana[nrofCollumns]=coloana_noua;
			
		
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
		//it erases the adress of the vector

	}

};


class ALLTables:TABLE {
public:
	TABLE* tabele;
	int nrOfTables;

	ALLTables()
	{
		this->nrOfTables = 0;
		this->tabele = new TABLE[10];

	}

	bool tableVerification(string numeTabel)
	{
		int ok = 0;
		for (int i = 0; i < nrOfTables; i++)
		{
			if (tabele[i].tableName == numeTabel)
				ok++;

		}
		if (ok == 0)
			return true;
		else
			return false;
	}

	void addNewTable(TABLE &tabel1,int nrOfTables)
	{
		
		
			this->tabele[nrOfTables] = tabel1;
		
		
	}

	TABLE getTable(int nrOfTables)
	{
		return tabele[nrOfTables];
	}
	void addTables()
	{
		this->nrOfTables = nrOfTables + 1;
	}

	~ALLTables() {
		
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

					//default value
					secCommand = strtok_s(NULL, " ,()", &next_token);
					s = lower(secCommand);
					
					ELEMENTE element1;
					element1.addElemente(s);
					for (int i = 0; i < 10; i++)
					{
						coloana1.addELEMENTE(element1,i);
					}

					
					tabel1.addCOLLUMNS(coloana1,tabel1.nrofCollumns);
					tabel1.addColoane();
					
					database.addNewTable(tabel1,database.nrOfTables);
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