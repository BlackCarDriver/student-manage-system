#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include<Windows.h>
#include<winsock.h>
#include<mysql.h>

#include"SqlPackage.h"
#include"student.h"
using namespace std;

#define SCUUEED 1
#define FATAL	-1
#define	WORNG	-2
#define TEACHER 3
#define	STUDENT	9
#define MANAGER	27

void Student::setId(string id){
	this->id = id;
}

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
	string viewSql = "SELECT * FROM v_grade WHERE id = '$1'";
	viewSql = SqlPackage::makeSql(viewSql, { this->id });
	SqlPackage::printTable(viewSql, 15);
	puts("input anything to continue");
	char block[100];
	cin.ignore();
	cin.getline(block, 99);
}

void Student::checkSource(){
	puts("The following is your source:");
	string viewSql = "SELECT * FROM v_select WHERE student_id = '$1'";
	viewSql = SqlPackage::makeSql(viewSql, { this->id });
	SqlPackage::printTable(viewSql);
	puts("input anything to continue");
	char block[100];
	cin.ignore();
	cin.getline(block, 99);
}

void Student::addSource(){
	string sourceId;
	printf("Please input the id of source you want to add > ");
	cin >> sourceId;
	string insertSql = "INSERT INTO t_select (stdid,courid)VALUES('$1','$2')";
	insertSql = SqlPackage::makeSql(insertSql, {this->id, sourceId});
	int res = SqlPackage::insert(insertSql);
	if (res == SCUUEED){
		puts("Add source scuueed!");
	}
	else{
		puts("Add source fall!");
	}
	puts("input anything to continue");
	char block[100];
	cin.ignore();
	cin.getline(block, 99);
}

void Student::setPassword(){
	string password;
	printf("Please input a new password or 'cancel' to git up > ");
	cin >> password;
	if (password == "cancel"){
		return;
	}
	string updateSql = "UPDATE t_account SET PASSWORD = '$1' WHERE id = '$2'";
	updateSql = SqlPackage::makeSql(updateSql, { password, this->id });
	int result = SqlPackage::exec(updateSql);
	if (result == SCUUEED){
		puts("Your password scuueedfuly change!");
	}
	else{
		puts("Sorry, change password fall!");
	}
	puts("input anything to continue");
	char block[100];
	cin.ignore();
	cin.getline(block, 99);
}

void Student::printfFunction(){
	system("cls");
	puts("======================== Welcome to blackcar system =======================");
	puts("You can do the following :");
	puts("check your grade by input 'checkGrade' ");
	puts("check your source by input 'checkSource' ");
	puts("select more source by input 'addSource'");
	puts("change your password by input 'changePassword'");
	puts("Quit by input 'quit' ");
	puts("===========================================================================");
}

