#pragma once

class ALLTables {
public:
	TABLE** tabele;
};

class TABLE
{
public:
	char* tableName;
	COLLUMN* coloana;

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

	void setType(const char* type)
	{
		type = new char[strlen(type)];
		strcpy_s(this->type, strlen(type) + 1, type);
	}

	void setElemente(char** elemente, int lines, const char* value)
	{
		if (elemente==NULL)
		{
			this->lines = lines;
			
			elemente = new char*[lines*sizeof(char*)];
			for (int i = 0; i < lines; i++)
				elemente[i] = new char(maxlenght * sizeof(char));
		}
		for (int i = 0; i < lines; i++)
		{
			strcpy_s(elemente[i], strlen(value + 1), value);
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