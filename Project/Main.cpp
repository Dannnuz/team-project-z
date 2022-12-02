#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include "MyCLass.h"
using namespace std;






int main()
{
	char command[100];
	cin.getline(command, 100);
	int n = 10;


	TABLE tabel1("order", 1);

	cout<<tabel1.getTableName();
	/*
	while (strcmp(command, "quit")!=0)
	{
	
		cin.getline(command, 100);
	}
	*/
	COLLUMN coloana1;
	
	coloana1.setColName(command);
/*
	tabel1.addColoane();
	COLLUMN* coloana;

	for (int i = 0; i < tabel1.nrofCollumns; i++)
	{
		coloana[i]("Buna",20,"ziua",nullptr,0);
	}
	*/
	

}

	