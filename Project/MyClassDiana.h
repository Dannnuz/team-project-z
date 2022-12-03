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

//the class for the collumns
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

	void addELEMENTE(ELEMENTE& element, int nr_elemente)
	{
		this->elemente[nr_elemente] = element;

	}

	void addNrElemente()
	{
		this->nr_elemente = nr_elemente + 1;
	}

	COLLUMN& operator=(const COLLUMN& c)
	{
		if (this != &c)
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

//the class for the table which inherits collumn
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


	void addCOLLUMNS(COLLUMN& coloana_noua, int nrofCollumns)
	{

		this->coloana[nrofCollumns] = coloana_noua;


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
		this->nrofCollumns = nrofCollumns + 1;

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

//the class that contains all tables created, which inherits table
class ALLTables :TABLE {
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

	void addNewTable(TABLE& tabel1, int nrOfTables)
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

//the class for indexes
class INDEXES:COLLUMN{
	string* indexName;
	COLUMN* coloana;

	INDEX() {
		indexName = NULL;
	}

	INDEX(string* indexName) {
		this->indexName = indexName;
	}
	
	~INDEX() {
	
	}

	void setIndex() {
		
	}

	string getIndex() {
		if (this->indexName != NULL)
			return this->indexName;
		else
			return "Index does not exist";
	}

};

char* lower(char comanda[])
{
	for (int i = 0; comanda[i] != NULL; i++)
	{
		comanda[i] = tolower(comanda[i]);
	}

	return comanda;
}

//function for validating and using the commands
void findMyCommand(char* command, ALLTables& database)
{
	string s;
	char* next_token;
	char* secCommand = strtok_s(command, " ", &next_token);
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
					secCommand = strtok_s(NULL, " ,()", &next_token);
					while (secCommand)
					{
						//we create a local object of COLLUMN class
						COLLUMN coloana1;
						//here we must introuce at least 1 collumn to the table


						//column name

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
							coloana1.addELEMENTE(element1, i);
						}

						//here we copy the collumn into the table
						tabel1.addCOLLUMNS(coloana1, tabel1.nrofCollumns);
						tabel1.addColoane();

						secCommand = strtok_s(NULL, " ,()", &next_token);
					}
					//here we copy the table into the database
					database.addNewTable(tabel1, database.nrOfTables);
					database.addTables();

				}
				else
				{
					cout << "The table's name is already in the database" << endl;

					//the table's name is already in the database
				}



			}
		}
		//create index-command
		else if (strcmp(lower(secCommand), "index") == 0)
		{
			//the index name
			secCommand = strtok_s(NULL, " ", &next_token);
			//verify if we have an index name
			if (secCommand != NULL) {
				
			}

		}
		//wrong input case
		else
		{

		}
	}//drop - command
	else if (strcmp(lower(secCommand), "drop") == 0)
	{
		secCommand = strtok_s(NULL, " ", &next_token);

		if (strcmp(lower(secCommand), "table") == 0)
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

	////insert into - command
	//else if (strcmp(lower(secCommand), "insert") == 0)
	//{
	//	secCommand = strtok_s(NULL, " ", &next_token);
	//	if (strcmp(lower(secCommand), "into") == 0)
	//	{
	//		secCommand = strtok_s(NULL, " ", &next_token);
	//	}
	//	else
	//	{
	//		//wrong input case
	//	}

	//}

	////delete from - command
	//else if (strcmp(lower(secCommand), "delete") == 0)
	//{
	//	secCommand = strtok_s(NULL, " ", &next_token);
	//	if (strcmp(lower(secCommand), "from") == 0)
	//	{
	//		secCommand = strtok_s(NULL, "", &next_token);
	//	}
	//	else
	//	{
	//		//wrong input case
	//	}
	//}

	////select from - command
	//else if (strcmp(lower(secComand), "select") == 0)
	//{
	//	secCommand = strtok_s(NULL, " ", &next_token);
	//	if (strcmp(lower(secCommand), "all") == 0)
	//	{
	//		secCommand = strtok_s(NULL, " ", &next_token);
	//		if (strcmp(lower(secCommand), "from") == 0)
	//		{
	//			secCommand = strtok_s(NULL, " ", &next_token);
	//		}
	//		else
	//		{
	//			//wrong input case
	//		}
	//	}
	//	else
	//	{
	//		//wrong input case
	//	}
	//}

	////update - command
	//else if (strcmp(lower(secCommand), "update") == 0) {
	//	secCommand = strtok_s(NULL, " ", &next_token);
	//}
