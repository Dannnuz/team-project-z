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


	char* next_token;
	char* secCommand = strtok_s(command, " ", &next_token);


	if (strcmp(lower(secCommand), "create") == 0)
	{
		cout << "ok"<<endl;
		secCommand = strtok_s(NULL," ", &next_token);
		if (strcmp(lower(secCommand), "table") == 0)
		{
			//the table's name
			secCommand = strtok_s(NULL," ", &next_token);
			//verify id the table's name is already used
			if(secCommand!=NULL)
			cout << secCommand;
		}
	}

	

	

}

	