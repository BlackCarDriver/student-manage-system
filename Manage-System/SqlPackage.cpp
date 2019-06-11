#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<winsock.h>
#include<mysql.h>
#include"mysql-package.h"
#define SCUUEED 1
#define FATAL	-1
using namespace std;

const char* host = "localhost";
const char* user = "root";
const char* password = "123456";
const char* database = "mysql";
const  int port = 3306;


int SqlPackage::init(){
	mysql_init(&conn);
	bool is_scueed = mysql_real_connect(&conn, host, user, password, database, port, NULL, 0);
	if (!is_scueed){
		fprintf(stderr, "Failed to connect to database: Error: %s\n", mysql_error(&conn));
		return	FATAL;
	} 
	printf("Connect database scuueed! \n");
	return	SCUUEED;
}

SqlPackage::SqlPackage(){
	int res = init();
	if (res == FATAL){
		exit(1);
	}
}

SqlPackage::~SqlPackage(){
	mysql_close(&conn);
}

void SqlPackage::test(){	
		int status = mysql_query(&conn, "SELECT * FROM user");
		res_set = mysql_store_result(&conn);
		int count = mysql_num_rows(res_set);
		printf("No of rows = %d\n", count);
		while ((row = mysql_fetch_row(res_set)) != NULL){
			for (int i = 0; i<mysql_num_fields(res_set); i++){
				printf("%s \t", row[i] != NULL ? row[i] : "NULL");
			}
			printf("\n");
		}
	
	getchar();
}

