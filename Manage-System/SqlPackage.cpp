#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<winsock.h>
#include<mysql.h>
#include<vector>
#include"mysql-package.h"

#define SCUUEED 1
#define FATAL	-1
#define	WORNG	-2
#define TEACHER 3
#define	STUDENT	9
#define MANAGER	27

using namespace std;

const char* host = "localhost";
const char* user = "root";
const char* password = "123456";
const char* database = "school";
const  int port = 3306;


SqlPackage::SqlPackage(){
	int res = init();
	if (res == FATAL){
		exit(1);
	}
}

SqlPackage::~SqlPackage(){
	mysql_close(&conn);
}

int SqlPackage::init(){
	mysql_init(&conn);
	bool is_scueed = mysql_real_connect(&conn, host, user, password, database, port, NULL, 0);
	if (!is_scueed){
		fprintf(stderr, "Failed to connect to database: Error: %s\n", mysql_error(&conn));
		return	FATAL;
	}
	mysql_query(&conn, "SET NAMES utf8");
	printf("Connect database scuueed! \n");
	return	SCUUEED;
}

void SqlPackage::testQuery(){	
	string queryStr = "select * from t_account";
	string result = query(queryStr,15);
	cout << result << endl;
}

void SqlPackage::testExec(){
	string insertStr = "INSERT INTO t_account(id,NAME,TYPE)VALUES('1234571','test2','manager');";
	string deleteStr = "delete from t_account where name ='test2'";
	string updateStr = "UPDATE t_account SET NAME = 'test2' WHERE id = '1234570'";
	int res = exec(updateStr);
	if (res == SCUUEED){
		puts("scuueed!");
	}
	else{
		puts("Fall!");
	}
}

void SqlPackage::testOther(){
	makeSql("select * from t_account where name = $1",{ "test" });
}

string SqlPackage::query(string queryStr, int interval){
	int status = mysql_query(&conn, queryStr.c_str());
	res_set = mysql_store_result(&conn);
	int count = mysql_num_rows(res_set);
	if (count <= 0){
		return "no result ... ";
	}
	string result = "";
	result += getTableHead(res_set, interval);
	int colNum = mysql_num_fields(res_set);
	while ((row = mysql_fetch_row(res_set)) != NULL){
		for (int i = 0; i< colNum; i++){
			string tmp = (row[i] != NULL ? row[i] : "NULL");
			tmp.resize(interval, ' ');
			result += tmp;
		}
		result += "\n";
	}
	mysql_free_result(res_set);
	return result;
}

string SqlPackage::getTableHead(MYSQL_RES* res, int interval){
	string tableHead = "";
	int colNum = mysql_num_fields(res);
	MYSQL_FIELD* field = mysql_fetch_fields(res);
	for (int i = 0; i < colNum; i++){
		string colName = field[i].name;
		colName.resize(interval, ' ');
		tableHead += colName;
	}
	tableHead += "\n";
	string tmp = "-";
	tmp.resize(interval*colNum, '-');
	tableHead += tmp;
	tableHead += "\n";
	return tableHead;
}

int SqlPackage::exec(string ope){
	if ( mysql_query(&conn, ope.c_str()) ){
		return FATAL;
	}
	return SCUUEED;
}

//return worng or the identifi of user
int SqlPackage::login(string id, string password){
	int result = WORNG;
	//do something....
	if (id == "teacher") result = TEACHER;
	if (id == "student") result = STUDENT;
	if (id == "manager") result == MANAGER;
	//do something...
	return result;
}

string SqlPackage::makeSql(string format, vector<string> strVec){
	string result = format;
	for (int i = 1; i <= strVec.size(); i++){
		string target = "$" + to_string(i);
		auto p = result.find(target);
		result = result.replace(p, 2 , strVec[i-1]);
	}
	return result;
};
