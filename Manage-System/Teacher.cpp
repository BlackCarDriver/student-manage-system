#pragma once
#include<stdio.h>
#include<iostream>
#include<string>
#include<Windows.h>
#include<winsock.h>
#include<mysql.h>

#include"SqlPackage.h"
#include"teacher.h"
using namespace std;

#define SCUUEED 1
#define FATAL	-1
#define	WORNG	-2
#define TEACHER 3
#define	STUDENT	9
#define MANAGER	27

void Teacher::setId(string id){
	this->id = id;
}

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
	string viewSql = "SELECT * FROM t_course WHERE teacherid='$1'";
	viewSql = SqlPackage::makeSql(viewSql, { this->id });
	puts("the following is your source:");
	SqlPackage::printTable(viewSql);
	puts("input anything to continue");
	char block[100];
	cin.ignore();
	cin.getline(block, 99);
}

void Teacher::checkStudent(){
	string viewSql = "SELECT * FROM v_studentList WHERE teacher_id = '$1'";
	viewSql = SqlPackage::makeSql(viewSql, { this->id });
	puts("the following is your students:");
	SqlPackage::printTable(viewSql);
	puts("input anything to continue");
	char block[100];
	cin.ignore();
	cin.getline(block, 99);
}

void Teacher::setGrade(){
	string studentId, courseId;
	double grade;
	printf("please input id of your studnet >");
	cin >> studentId;
	printf("Please input id of your source >");
	cin >> courseId;
	printf("Please input the source smaller than 100 and not smaller than 0 >");
	cin >> grade;
	cout << grade << endl;
	if (grade >= 0 && grade <= 100){
		string alterSql = "UPDATE t_grade SET grade = $1 WHERE student_id = '$2' AND course_id='$3'";
		alterSql = SqlPackage::makeSql(alterSql, { to_string(grade), studentId, courseId });
		int result = SqlPackage::exec(alterSql);
		if (result == SCUUEED){
			puts("Update grade scuueed!");
		}
		else{
			puts("Update grade fall!");
		}
	}
	else{
		puts("Your input seem not right !");
	}
	puts("input anything to continue");
	char block[100];
	cin.ignore();
	cin.getline(block, 99);
}

void Teacher::printfFunction(){
	system("cls");
	puts("======================== Welcome to blackcar system =======================");
	puts("You can do the following :");
	puts("check your source by input 'checkSource' ");
	puts("check your students by input 'checkStudent' ");
	puts("set your studnet grade by input 'setGrade'");
	puts("Quit by input 'quit' ");
	puts("===========================================================================");
}