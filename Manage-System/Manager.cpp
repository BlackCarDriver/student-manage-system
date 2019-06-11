#include<stdio.h>
#include<iostream>
#include<string>
#include<Windows.h>

#include"manager.h"
using namespace std;

void Manager::test(){
	printf("Manager work!\n");
}


int Manager::run(){
	string input="";
	while ( input != "quit"){
		printfFunction();
		cin >> input;
		if (input == "addAccount"){
			cout << input << endl;
			addAccount();
			continue;
		}
		if (input == "checkStatic"){
			cout << input << endl;
			checkStatic();
			continue;
		}
	}
	return 0;
}

int Manager::addAccount(){
	string id, name, type;
	printf("Please input the id of new account: > ");
	cin >> id;
	printf("Please input the name of it account: > ");
	cin >> name;
	printf("Please input the type of it account: > ");
	cin >> type;

	int result = 1;
	//do somthing

	return result;
}

void Manager::checkStatic(){
	//do somthing
}


void Manager::printfFunction(){
	system("cls");
	puts("======================== Welcome to blackcar system =======================");
	puts("You can do the following :");
	puts("Create an new account by input 'addAccount' ");
	puts("Get the static message by input 'checkStatic' ");
	puts("Quit by input 'quit' ");
	puts("===========================================================================");
}