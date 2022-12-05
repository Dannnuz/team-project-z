#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include "MyCLass.h"
#include<string>
using namespace std;






int main()
{
	char command[100];
	/*cin.getline(command, 100);*/
	int n = 10;


	/*TABLE tabel1("order", 1);

	cout<<tabel1.getTableName();*/
	/*
	while (strcmp(command, "quit")!=0)
	{
	
		cin.getline(command, 100);
	}
	*/
	ALLTables database;
	//COLLUMN coloana1;

	//coloana1.setSize(2);
	//coloana1.setColName("coloana1");
	//tabel1.addColoane();
	//
	////this is how u introduce values in the collumn vector in table's class
	//	tabel1.coloana.push_back(coloana1);

	//	tabel1.coloana.push_back(coloana1);
	//
	//	tabel1.coloana.push_back(coloana1);
 //  //this is how u introduce tables in the database
	//	database.tabele.push_back(tabel1);

	//create table tabelnou ((masini,char,20,logan),(clienti,char,10,marcel),(george,char,10,pensie)
	//create table tabelnou2 ((masini,char,20,logan),(clienti,char,10,marcel),(george,char,10,pensie)
	//delete from tabelnou where column_name = clienti
	//insert into tabelnou (mercedes,danutz,salariu)
	//insert into tabelnou (toyota,ion,bitcoin)
	//display table tabelnou
	//update tabelnou set column_name = masini_sport where column_name = masini
	while (strcmp(command, "quit") != 0)
	{
		cin.getline(command, 100);
		findMyCommand(command, database);
	}
	
	
	cout << database.tabele[0].nrofCollumns;
} 