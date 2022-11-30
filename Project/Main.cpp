#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void CreateTable() 
{

}

void CreateIndex() 
{

}

void DropTable()
{

}

void DropIndex()
{

}

void DisplayTable()
{

}

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
	const char* ch = " ";
	char command[100];
	cin.getline(command, 100);
	char* next_token;
	char* secCommand = strtok_s(command," ",&next_token);
	cout << secCommand;
	secCommand = strtok_s(NULL, " ", &next_token);
	cout << secCommand;
	secCommand = strtok_s(NULL, " ", &next_token);
	cout << secCommand;
} 