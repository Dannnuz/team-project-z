#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include "MyCLass.h"
#include<string>
using namespace std;






int main()
{
	char command[200];
	
	ALLTables database;
	
	//THESE ARE COMMANDS VERIFIED THAT WORK
	
	
	//create table tabelnou ((masini,text,20,logan),(clienti,text,10,marcel),(venit_luna,text,10,pensie))
	
	//delete from tabelnou where column_name = clienti
	
	//insert into tabelnou (mercedes,danut,salariu)
	
	//insert into tabelnou (toyota,ion,bitcoin)
	
	//display table tabelnou
	
	//update tabelnou set column_name = masini_sport where column_name = masini
	
	//create index coloana_cool on tabelnou (masini)
	
	//drop index coloana_cool
	
	//select masini_sport from tabelnou where id = 1
	
	//select all from tabelnou where id = 2

	//here is a loop where we can introduce commands an modify the database
	
	while (strcmp(command, "quit") != 0)
	{
		cin.getline(command, 100);
		findMyCommand(command, database);
		
	}
	

	
	//HOW IT WORKS
	//I created 4 classes that stores all the tables(with all their values) in the AllTables class(database)
	//ALl classes:
	//ALLTables
	//TABLE
	//COLLUMN
	//ELEMENTE
	//by compiling the program there is a loop where u insert commands 1 by 1 an therefore modyfy the database variable

	//MENTIONS
	//The project works just fine for commands that are written correctly( I couldn't manage to create 
	//a function that verify if the input between paranthesis is correct) 
	//there is still a lot of work to do,but we are working on it
	//sorry for not being able to complete phase 1 entirely by the deadline

} 