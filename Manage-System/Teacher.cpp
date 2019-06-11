#include<stdio.h>
#include<iostream>
#include<string>
#include"teacher.h"
using namespace std;

void Teacher::test(){
	printf("teacher work!\n");
}

int Teacher::run(){
	string input = "";
	while (input != "quit"){
		printfFunction();
		cin >> input;
		if (input == "checkSource"){
			cout << input << endl;
			checkSource();
			continue;
		}
		if (input == "checkStudent"){
			cout << input << endl;
			checkStudent();
			continue;
		}
		if (input == "setGrade"){
			cout << input << endl;
			setGrade();
			continue;
		}
	}
	return 0;
}

void Teacher::checkSource(){
	puts("the following is your source:");
	//do something..
}

void Teacher::checkStudent(){
	puts("the following is your students:");
	//do something ...
}

void Teacher::setGrade(){
	string studentId, SourceId;
	double grade;
	printf("please input id of your studnet >");
	cin >> studentId;
	printf("Please input id of your source >");
	cin >> SourceId;
	printf("Please input the source smaller than 100 and not smaller than 0 >");
	cin >> grade;
	if (grade <= 100 && grade <= 0){
	//do something....
	}
	else{
		puts("Your input seem not right !");
	}
}

void Teacher::printfFunction(){
	system("cls");
	puts("======================== Welcome to blackcar system =======================");
	puts("You can do the following :");
	puts("check your source by input 'checkSrouce' ");
	puts("check your students by input 'checkStudent' ");
	puts("set your studnet grade by input 'setGrade'");
	puts("Quit by input 'quit' ");
	puts("===========================================================================");
}