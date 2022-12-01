#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include "MyCLass.h"
using namespace std;



char* lower(char comanda[])
{
	for (int i = 0; comanda[i] != NULL; i++)
	{
		comanda[i] = tolower(comanda[i]);
	}
	
	return comanda;
}


int main()
{
	char command[100];
	cin.getline(command, 100);

	ALLTables database;


	

	

}

	