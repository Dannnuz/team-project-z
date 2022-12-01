#pragma once

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
};

class TABLE
{
public:
	char* tableName;
	COLLUMN* coloana;
	int nrofCollumns;

	TABLE()
	{
		this->tableName = NULL;
		this->nrofCollumns = 0;
	}

	~TABLE()
		{

		}
	
};


class COLLUMN
{
public:
	char* colName;
	int size;
	char* type;
	char** elemente;
	int lines;
	const int maxlenght=100;

	COLLUMN()
	{
		this->size = 0;
		this->colName = NULL;
		this->type = NULL;
		this->lines = 0;
		this->elemente = NULL;
		
	}

	void setSize(int size)
	{
		this->size = size;
	}

	void setColName(const char* colName)
	{
		colName = new char[strlen(colName)];
		strcpy_s(this->colName, strlen(colName) + 1, colName);
    }

	void setType(const char* type)
	{
		type = new char[strlen(type)];
		strcpy_s(this->type, strlen(type) + 1, type);
	}

	void setElemente( int lines, const char* value)
	{
		if (this->elemente==NULL)
		{
			this->lines = lines;
			
			this->elemente = new char*[lines*sizeof(char*)];
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
		this->lines = lines+1;

	}

	~COLLUMN() {
		delete[] colName;
		delete[] type;

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

void findMyCommand(char* command,ALLTables database)
{
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
			//verify id the table's name is not null
			if (secCommand != NULL)
			{
				//verify if the table's name is not already in the database
				if (database.tableVerification(secCommand))
				{
					//here we must introuce at least 1 collumn to the table
				}
				else
				{
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