#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<winsock.h>
#include<mysql.h>
#include<windows.h>

#include"SqlPackage.h"
#include"teacher.h"
#include"manager.h"
#include"student.h"

#define	WORNG	-2
#define TEACHER 3
#define	STUDENT	9
#define MANAGER	27

using namespace std;

SqlPackage sql;
Teacher teacher;
Manager manager;
Student student;

//Account mainly used to save the id of the user. 
//Account.id will be used very frequently by Teacher and Student class.
struct Account {
	string id;
	string password;
}account;


void printfWelcome(){
	system("cls");
	puts("========================================================");
	puts("=                                                      =");
	puts("=         Welcome to BlackCarDriver Club System        =");
	puts("=                                                      =");
	puts("========================================================");
	puts("input any key to continue ...");
	char block[100];
	cin.getline(block, 99);
}

int login(){
	system("cls");
	printf("Please Input your account: > ");
	cin >> account.id;
	for (int change = 1; change <= 3; change++){
		printf("Please Input your password: > ");
		cin >> account.password;
		int status = sql.login(account.id, account.password);
		if (status != WORNG) {
			return status;
		}
		puts("Sorry, no such account or password worng, please try againt!");
	}
	puts("Password not right ! input anything to continue....");
	string tmp;
	cin >> tmp;
	return WORNG;
}

int main(){
	//sql.testQuery();
	//sql.testExec();
	//sql.testOther();
	//return 0;
	printfWelcome();
	int status;
	while (status = login()){
		system("cls");
		cout << status<<"###\n";
		switch (status){
		case STUDENT:
			student.setId(account.id);
			student.run();
			break;
		case TEACHER:
			teacher.setId(account.id);
			teacher.run();
			break;
		case MANAGER:
		  	manager.setId(account.id);
			manager.run();
			break;
		default:
			break;
		}

		if (status != WORNG){
			break;
		}
	}
	return 0;
}

