#pragma once
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


class COLLUMN
{
public:
	char* colName;
	int size;
	char* type;
	char** elemente;
	int lines;
	const int maxlenght = 100;

	COLLUMN()
	{
		this->size = 0;
		this->colName = NULL;
		this->type = NULL;
		this->lines = 0;
		this->elemente = NULL;

	}

	COLLUMN(char* colName, int size, const char* type, char** elemente, int lines)
	{

		this->colName = new char[strlen(colName)];
		strcpy_s(this->colName, strlen(colName) + 1, colName);

		type = new char[strlen(type)];
		strcpy_s(this->type, strlen(type) + 1, type);

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

	void setColName(const char* colName)
	{
		this->colName = new char[strlen(colName)];
		strcpy_s(this->colName, strlen(colName) + 1, colName);
    }

	void setType(const char* type)
	{
		type = new char[strlen(type)];
		strcpy_s(this->type, strlen(type) + 1, type);
	}

	void setElemente( int lines, const char* value)
	{
		if (this->elemente == NULL)
		{
			this->lines = lines;

			this->elemente = new char* [lines * sizeof(char*)];
			for (int i = 0; i < lines; i++)
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

	COLLUMN& operator=(const COLLUMN& c)
	{
		if (this  != &c)
		{
			this->colName = new char[strlen(c.colName)];
			strcpy_s(this->colName, strlen(c.colName) + 1, c.colName);

			type = new char[strlen(c.type)];
			strcpy_s(this->type, strlen(c.type) + 1,c.type);

			if (this->elemente == NULL)
			{
				this->lines = c.lines;

				this->elemente = new char* [c.lines * sizeof(char*)];
				for (int i = 0; i < lines; i++)
					this->elemente[i] = new char(c.maxlenght * sizeof(char));
			}
			
		
		}
		return *this;
	}

	~COLLUMN() {
		delete[] colName;
		delete[] type;

	}

};


class TABLE:COLLUMN
{
public:
	char* tableName;
	COLLUMN* coloana;
	int nrofCollumns;

	TABLE()
	{
		this->tableName = NULL;
		this->nrofCollumns = 0;
		this->coloana = NULL;
		
	}

	TABLE(const char* tableName, int nrofCollumns)
	{
		this->tableName = new char[strlen(tableName) + 1];
		strcpy_s(this->tableName, strlen(tableName) + 1, tableName);

		this->nrofCollumns = nrofCollumns;
		this->coloana = NULL;
	}

	void addColoane()
	{
		this->nrofCollumns = nrofCollumns+1;

	}

	void addCOLLUMN(COLLUMN coloana,int i)
	{
		this->coloana[i] = coloana;
	
	}

	char* getTableName()
	{
		return this->tableName;
	}

	~TABLE()
	{
		delete[] tableName;

	}

};


class ALLTables {
public:
	TABLE* tabele;
	int nrOfTables;

	ALLTables()
	{
		this->nrOfTables = 0;

	}

	bool tableVerification(const char* numeTabel)
	{
		int ok = 0;
		for (int i = 0; i < nrOfTables; i++)
		{
			if (strcmp(tabele[i].tableName, numeTabel) == 0)
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

void findMyCommand(char* command, ALLTables database)
{
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
			//verify id the table's name is not null
			if (secCommand != NULL)
			{
				//verify if the table's name is not already in the database
				if (database.tableVerification(secCommand))
				{
					//here we must introuce at least 1 collumn to the table
					database.addTables();
					
					

					//column name
					secCommand = strtok_s(NULL, " ,()", &next_token);
					

					//type of collumn
					secCommand = strtok_s(NULL, " ,()", &next_token);
					

					//size
					secCommand = strtok_s(NULL, " ,()", &next_token);
					int x = atoi(secCommand);
					
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