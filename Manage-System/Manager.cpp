#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include<Windows.h>
#include<winsock.h>
#include<mysql.h>

#include"SqlPackage.h"
#include"manager.h"

#define SCUUEED 1
#define FATAL	-1
#define	WORNG	-2
#define TEACHER 3
#define	STUDENT	9
#define MANAGER	27

using namespace std;

void Manager::setId(string id){
	this->id = id;
}

void Manager::test(){
	printf("Manager work!\n");
}

int Manager::run(){
	string input="";
	while ( input != "quit"){
		printfFunction();
		cin >> input;
		if (input == "addAccount"){
			addAccount();
			continue;
		}
		if (input == "checkStatic"){
			checkStatic();
			continue;
		}
	}
	return 0;
}

void Manager::addAccount(){
	string id, name, type;
	printf("Please input the id of new account: > ");
	cin >> id;
	printf("Please input the name of it account: > ");
	cin >> name;
	printf("Please input the type of it account: > ");
	cin >> type;
	string sqlTemplage = "insert into t_account(id,NAME,TYPE)VALUES('$1','$2','$3')";
	sqlTemplage = makeSql(sqlTemplage, { id, name, type });
	int res = SqlPackage::exec(sqlTemplage);
	if (res == SCUUEED){
		puts("Create account scuueed!");
	}
	else{
		puts("Create account fall!");
	}
	puts("input anything to continue");
	char block[100];
	cin.ignore();
	cin.getline(block, 99);
}

void Manager::checkStatic(){
	string checkSql = "SELECT TYPE AS usertype, COUNT(*) AS numbers FROM t_account GROUP BY TYPE";
	SqlPackage::printTable(checkSql);
	puts("input anything to continue");
	char block[100];
	cin.ignore();
	cin.getline(block, 99);
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