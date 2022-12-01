#pragma once

class ALLTables {
public:
	TABLE** tabele;
	int nrOfTables;
};

class TABLE
{
public:
	char* tableName;
	COLLUMN* coloana;
	int nrofCollumns;
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
	// this function is meant to set the type of the collumn
	void setType(const char* type) 
	{
		type = new char[strlen(type)];
		strcpy_s(this->type, strlen(type) + 1, type);
	}
	// this function is meant to set the element in collumn
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

class CreateTable {
	TABLE tabel;



	
};


class DropTable {



};

class DisplayTable {

};

class DropIndex {

};

class CreateIndex {

};

void findMyCommand(char* command)
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
			//verify id the table's name is already used
			if (secCommand != NULL)
			{
				cout << secCommand;
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

}