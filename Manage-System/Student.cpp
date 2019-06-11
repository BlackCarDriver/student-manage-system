#include<stdio.h>
#include<iostream>
#include<string>
#include"student.h"
using namespace std;

void Student::test(){
	printf("studnet work!\n");
}

int Student::run(){
	string input = "";
	while (input != "quit"){
		printfFunction();
		cin >> input;
		if (input == "checkGrade"){
			checkGrade();
			continue;
		}
		if (input == "checkSource"){
			checkSource();
			continue;
		}
		if (input == "addSource"){
			addSource();
			continue;
		}
		if (input == "changePassword"){
			setPassword();
			continue;
		}
	}
	return 0;
}

void Student::checkGrade(){
	puts("The following is your grade:");
	//dosomething
}

void Student::checkSource(){
	puts("The following is your source:");
	//dosomething
}


void Student::addSource(){
	string sourceId;
	printf("Please input the id of source you want to add > ");
	cin >> sourceId;
	//do something
}

void Student::setPassword(){
	string password;
	printf("Please input a new password or 'cancel' to git up > ");
	if (password != "cancel"){
		//do something...
	}
	else{
		puts("Your password haven't change...");
	}
}

void Student::printfFunction(){
	system("cls");
	puts("======================== Welcome to blackcar system =======================");
	puts("You can do the following :");
	puts("check your grade by input 'checkGrade' ");
	puts("check your source by input 'checkSource' ");
	puts("select more source by input 'addSource'");
	puts("change your password by input 'change password'");
	puts("Quit by input 'quit' ");
	puts("===========================================================================");
}